#ifndef RENDERSYSTEMS_H_INCLUDED
#define RENDERSYSTEMS_H_INCLUDED

#ifdef __APPLE__
#include "Ogre/OgreMemoryMacros.h"
#include "Ogre/Ogre.h"
#else
//#include "OgreMemoryMacros.h"
#include "Ogre.h"
#endif
using namespace Ogre;
class renderSystems
{
	public:

    virtual Root *getMRoot();
    void setMRoot(Root *root);

    virtual Camera *getMCamera();
    void setMCamera(Camera *camera);

    virtual SceneManager *getMSceneMgr();
    void setMSceneMgr(SceneManager *sceneMgr);

    virtual RenderWindow *getMWindow();
    void setMWindow(RenderWindow *window);

    virtual Ogre::Vector3 getMTranslateVector();
    void setMTranslateVector(Ogre::Vector3 vector);

    virtual Radian getMRotX();
    void setMRotX(Radian rotX);

    virtual Radian getMRotY();
    void setMRotY(Radian rotY);

    virtual Real getMMoveSpeed();
    void setMMoveSpeed(Real speed);

    virtual Degree getMRotateSpeed();
    void setMRotateSpeed(Degree speed);

    virtual float getMMoveScale();
    void setMMoveScale(float scale);

    virtual Degree getMRotScale();
    void setMRotScale(Degree scale);

    virtual String getMResourceGroup();
    void setMResourceGroup(String resource);

    virtual ~renderSystems();

    static renderSystems *Instance();

	protected:
    renderSystems();
    renderSystems(const renderSystems&);
    renderSystems& operator= (const renderSystems&);

    Root *mRoot;
    Camera *mCamera;
    SceneManager *mSceneMgr;
    RenderWindow *mWindow;
//	InputReader* mInputDevice;
    Ogre::Vector3 mTranslateVector;
    Radian mRotX, mRotY;
    Real mMoveSpeed;
    Degree mRotateSpeed;
    float mMoveScale;
    Degree mRotScale;

    String mResourceGroup;  // stores resource locations
    Real mTimeUntilNextToggle ;

    private:

    static renderSystems *pInstance;

};

#endif // RENDERSYSTEMS_H_INCLUDED
