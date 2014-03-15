package com.libolt.ubc;

import org.libsdl.app.SDLActivity;

import android.app.Activity;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.os.Bundle;
import android.os.Handler;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceHolder.Callback;
import android.view.SurfaceView;
import android.content.res.AssetManager;
import android.util.Log;

public class UBCActivity extends SDLActivity implements SensorEventListener {
	public native static void create(AssetManager mgr);	
	public native static void destroy();	
	public native static void initWindow(Surface surface);
	public native static void termWindow();
	public native static void renderOneFrame();
	
	protected Handler handler = null;
	protected SurfaceView surfaceView = null;
	protected Surface lastSurface = null;

	private Runnable renderer = null;
	private boolean paused = false;
	private boolean initOGRE = false;
	private AssetManager assetMgr = null;

	private static final String TAG = "SDL";

    // Keep track of the paused state
    public static boolean mIsPaused, mIsSurfaceReady, mHasFocus;
    public static boolean mExitCalledFromJava;

    // Main components
    protected static SDLActivity mSingleton;
    protected static SDLSurface mSurface;
    protected static View mTextEdit;
    protected static ViewGroup mLayout;
    protected static SDLJoystickHandler mJoystickHandler;

    // This is what SDL runs in. It invokes SDL_main(), eventually
    protected static Thread mSDLThread;

    // Audio
    protected static AudioTrack mAudioTrack;
	
	static {
		System.loadLibrary("SDL2");
        System.loadLibrary("UltimateBasketballChallenge");
    }	
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		Log.v("SDL", "onCreate():" + mSingleton);
        super.onCreate(savedInstanceState);

        SDLActivity.initialize();
        // So we can call stuff from static callbacks
        mSingleton = this;

        // Set up the surface
        mSurface = new SDLSurface(getApplication());

        if(Build.VERSION.SDK_INT >= 12) {
            mJoystickHandler = new SDLJoystickHandler_API12();
        }
        else {
            mJoystickHandler = new SDLJoystickHandler();
        }

        mLayout = new AbsoluteLayout(this);
        mLayout.addView(mSurface);

        setContentView(mLayout);
		super.onCreate(savedInstanceState);
		handler = new Handler();
		sysInit();
	}

	@Override
	protected void onPause() {
		super.onPause();
		handler.removeCallbacks(renderer);
		paused = true;
	}

	@Override
	protected void onResume() {
		super.onResume();
		paused = false;
		handler.post(renderer);
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();

		Runnable destroyer = new Runnable() {
			public void run() {
				UBCActivity.destroy();
			}
		};
		handler.post(destroyer);
	}

	private void sysInit() {
		final Runnable initRunnable = new Runnable() {
			public void run() {
				if (!initOGRE) {
					initOGRE = true;

					if(assetMgr == null) {
						assetMgr = getResources().getAssets();
					}

					UBCActivity.create(assetMgr);

					renderer = new Runnable() {
						public void run() {

							if (paused)
								return;

							if (!wndCreate && lastSurface != null) {
								wndCreate = true;
								UBCActivity.initWindow(lastSurface);
								handler.post(this);
								return;
							}

							if (initOGRE && wndCreate)
								UBCActivity.renderOneFrame();

							handler.post(this);
						}
					};

					handler.post(renderer);
				}
			}

		};

		SurfaceView view = new SurfaceView(this);
		SurfaceHolder holder = view.getHolder();
		// holder.setType(SurfaceHolder.SURFACE_TYPE_GPU);
		surfaceView = view;

		holder.addCallback(new Callback() {
				public void surfaceCreated(SurfaceHolder holder) {
					if (holder.getSurface() != null
						&& holder.getSurface().isValid()) {
						lastSurface = holder.getSurface();
						handler.post(initRunnable);
					}
				}

				public void surfaceDestroyed(SurfaceHolder holder) {
					if (initOGRE && wndCreate) {
						wndCreate = false;
						lastSurface = null;
						handler.post(new Runnable() {
								public void run() {
									UBCActivity.termWindow();
								}
							});
					}
				}

				public void surfaceChanged(SurfaceHolder holder, int format,
										   int width, int height) {

				}
			});
		setContentView(surfaceView);
	}

	boolean wndCreate = false;

	public void onAccuracyChanged(Sensor sensor, int accuracy) {

	}

	public void onSensorChanged(SensorEvent event) {
		if (event.sensor.getType() == Sensor.TYPE_ACCELEROMETER) {
		}
	}

	static {
//		System.loadLibrary("OgreJNI");
	}
}



