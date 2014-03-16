	.arch armv5te
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 4
	.eabi_attribute 18, 4
	.code	16
	.file	"btCollisionWorld.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text._ZN36btDiscreteCollisionDetectorInterface6ResultD2Ev,"axG",%progbits,_ZN36btDiscreteCollisionDetectorInterface6ResultD5Ev,comdat
	.align	1
	.weak	_ZN36btDiscreteCollisionDetectorInterface6ResultD2Ev
	.code	16
	.thumb_func
	.type	_ZN36btDiscreteCollisionDetectorInterface6ResultD2Ev, %function
_ZN36btDiscreteCollisionDetectorInterface6ResultD2Ev:
	.fnstart
.LFB515:
	.file 1 "jni/../../../bullet4droid/jni/src/BulletCollision/NarrowPhaseCollision/btDiscreteCollisionDetectorInterface.h"
	.loc 1 34 0
	.cfi_startproc
.LVL0:
	.loc 1 34 0
	ldr	r3, .L3
	@ sp needed for prologue
.LPIC1:
	add	r3, pc
.LBB6021:
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6021:
	bx	lr
.L4:
	.align	2
.L3:
	.word	_ZTVN36btDiscreteCollisionDetectorInterface6ResultE(GOT_PREL)+(.-(.LPIC1+4))
	.cfi_endproc
.LFE515:
	.fnend
	.size	_ZN36btDiscreteCollisionDetectorInterface6ResultD2Ev, .-_ZN36btDiscreteCollisionDetectorInterface6ResultD2Ev
	.section	.text._ZN16btManifoldResult20setShapeIdentifiersAEii,"axG",%progbits,_ZN16btManifoldResult20setShapeIdentifiersAEii,comdat
	.align	1
	.weak	_ZN16btManifoldResult20setShapeIdentifiersAEii
	.code	16
	.thumb_func
	.type	_ZN16btManifoldResult20setShapeIdentifiersAEii, %function
_ZN16btManifoldResult20setShapeIdentifiersAEii:
	.fnstart
.LFB552:
	.file 2 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionDispatch/btManifoldResult.h"
	.loc 2 84 0
	.cfi_startproc
.LVL1:
	.loc 2 86 0
	str	r1, [r0, #16]
	.loc 2 87 0
	str	r2, [r0, #24]
	.loc 2 88 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE552:
	.fnend
	.size	_ZN16btManifoldResult20setShapeIdentifiersAEii, .-_ZN16btManifoldResult20setShapeIdentifiersAEii
	.section	.text._ZN16btManifoldResult20setShapeIdentifiersBEii,"axG",%progbits,_ZN16btManifoldResult20setShapeIdentifiersBEii,comdat
	.align	1
	.weak	_ZN16btManifoldResult20setShapeIdentifiersBEii
	.code	16
	.thumb_func
	.type	_ZN16btManifoldResult20setShapeIdentifiersBEii, %function
_ZN16btManifoldResult20setShapeIdentifiersBEii:
	.fnstart
.LFB553:
	.loc 2 90 0
	.cfi_startproc
.LVL2:
	.loc 2 92 0
	str	r1, [r0, #20]
	.loc 2 93 0
	str	r2, [r0, #28]
	.loc 2 94 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE553:
	.fnend
	.size	_ZN16btManifoldResult20setShapeIdentifiersBEii, .-_ZN16btManifoldResult20setShapeIdentifiersBEii
	.section	.text._ZN24btBroadphaseAabbCallbackD2Ev,"axG",%progbits,_ZN24btBroadphaseAabbCallbackD5Ev,comdat
	.align	1
	.weak	_ZN24btBroadphaseAabbCallbackD2Ev
	.code	16
	.thumb_func
	.type	_ZN24btBroadphaseAabbCallbackD2Ev, %function
_ZN24btBroadphaseAabbCallbackD2Ev:
	.fnstart
.LFB625:
	.file 3 "jni/../../../bullet4droid/jni/src/BulletCollision/BroadphaseCollision/btBroadphaseInterface.h"
	.loc 3 31 0
	.cfi_startproc
.LVL3:
	.loc 3 31 0
	ldr	r3, .L9
	@ sp needed for prologue
.LPIC3:
	add	r3, pc
.LBB6022:
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6022:
	bx	lr
.L10:
	.align	2
.L9:
	.word	_ZTV24btBroadphaseAabbCallback(GOT_PREL)+(.-(.LPIC3+4))
	.cfi_endproc
.LFE625:
	.fnend
	.size	_ZN24btBroadphaseAabbCallbackD2Ev, .-_ZN24btBroadphaseAabbCallbackD2Ev
	.section	.text._ZN23btBroadphaseRayCallbackD2Ev,"axG",%progbits,_ZN23btBroadphaseRayCallbackD5Ev,comdat
	.align	1
	.weak	_ZN23btBroadphaseRayCallbackD2Ev
	.code	16
	.thumb_func
	.type	_ZN23btBroadphaseRayCallbackD2Ev, %function
_ZN23btBroadphaseRayCallbackD2Ev:
	.fnstart
.LFB629:
	.loc 3 43 0
	.cfi_startproc
.LVL4:
.LBB6023:
	.loc 3 43 0
	ldr	r3, .L14
.LBE6023:
	@ sp needed for prologue
.LBB6027:
.LPIC5:
	add	r3, pc
.LBB6024:
.LBB6025:
.LBB6026:
	.loc 3 31 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6026:
.LBE6025:
.LBE6024:
.LBE6027:
	.loc 3 43 0
	bx	lr
.L15:
	.align	2
.L14:
	.word	_ZTV24btBroadphaseAabbCallback(GOT_PREL)+(.-(.LPIC5+4))
	.cfi_endproc
.LFE629:
	.fnend
	.size	_ZN23btBroadphaseRayCallbackD2Ev, .-_ZN23btBroadphaseRayCallbackD2Ev
	.section	.text._ZN16btCollisionWorld14setDebugDrawerEP12btIDebugDraw,"axG",%progbits,_ZN16btCollisionWorld14setDebugDrawerEP12btIDebugDraw,comdat
	.align	1
	.weak	_ZN16btCollisionWorld14setDebugDrawerEP12btIDebugDraw
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld14setDebugDrawerEP12btIDebugDraw, %function
_ZN16btCollisionWorld14setDebugDrawerEP12btIDebugDraw:
	.fnstart
.LFB699:
	.file 4 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionDispatch/btCollisionWorld.h"
	.loc 4 150 0
	.cfi_startproc
.LVL5:
	.loc 4 152 0
	str	r1, [r0, #72]
	.loc 4 153 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE699:
	.fnend
	.size	_ZN16btCollisionWorld14setDebugDrawerEP12btIDebugDraw, .-_ZN16btCollisionWorld14setDebugDrawerEP12btIDebugDraw
	.section	.text._ZN16btCollisionWorld14getDebugDrawerEv,"axG",%progbits,_ZN16btCollisionWorld14getDebugDrawerEv,comdat
	.align	1
	.weak	_ZN16btCollisionWorld14getDebugDrawerEv
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld14getDebugDrawerEv, %function
_ZN16btCollisionWorld14getDebugDrawerEv:
	.fnstart
.LFB700:
	.loc 4 155 0
	.cfi_startproc
.LVL6:
	.loc 4 157 0 discriminator 1
	ldr	r0, [r0, #72]
.LVL7:
	.loc 4 158 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE700:
	.fnend
	.size	_ZN16btCollisionWorld14getDebugDrawerEv, .-_ZN16btCollisionWorld14getDebugDrawerEv
	.section	.text._ZN16btCollisionWorld17RayResultCallbackD2Ev,"axG",%progbits,_ZN16btCollisionWorld17RayResultCallbackD5Ev,comdat
	.align	1
	.weak	_ZN16btCollisionWorld17RayResultCallbackD2Ev
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld17RayResultCallbackD2Ev, %function
_ZN16btCollisionWorld17RayResultCallbackD2Ev:
	.fnstart
.LFB705:
	.loc 4 206 0
	.cfi_startproc
.LVL8:
	.loc 4 206 0
	ldr	r3, .L20
	.loc 4 208 0
	@ sp needed for prologue
	.loc 4 206 0
.LPIC8:
	add	r3, pc
.LBB6028:
	.loc 4 207 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6028:
	.loc 4 208 0
	bx	lr
.L21:
	.align	2
.L20:
	.word	_ZTVN16btCollisionWorld17RayResultCallbackE(GOT_PREL)+(.-(.LPIC8+4))
	.cfi_endproc
.LFE705:
	.fnend
	.size	_ZN16btCollisionWorld17RayResultCallbackD2Ev, .-_ZN16btCollisionWorld17RayResultCallbackD2Ev
	.section	.text._ZNK16btCollisionWorld17RayResultCallback14needsCollisionEP17btBroadphaseProxy,"axG",%progbits,_ZNK16btCollisionWorld17RayResultCallback14needsCollisionEP17btBroadphaseProxy,comdat
	.align	1
	.weak	_ZNK16btCollisionWorld17RayResultCallback14needsCollisionEP17btBroadphaseProxy
	.code	16
	.thumb_func
	.type	_ZNK16btCollisionWorld17RayResultCallback14needsCollisionEP17btBroadphaseProxy, %function
_ZNK16btCollisionWorld17RayResultCallback14needsCollisionEP17btBroadphaseProxy:
	.fnstart
.LFB712:
	.loc 4 224 0
	.cfi_startproc
.LVL9:
.LBB6029:
	.loc 4 226 0
	ldrh	r2, [r0, #14]
.LBE6029:
	.loc 4 224 0
	mov	r3, r0
.LBB6030:
	.loc 4 226 0
	ldrh	r0, [r1, #4]
.LVL10:
	.loc 4 227 0
	and	r0, r2
	.loc 4 227 0 is_stmt 0 discriminator 2
	lsl	r0, r0, #16
	asr	r0, r0, #16
	.loc 4 227 0
	beq	.L23
	.loc 4 227 0 discriminator 1
	ldrh	r0, [r3, #12]
	ldrh	r2, [r1, #6]
	and	r0, r2
	.loc 4 224 0 is_stmt 1
	sub	r3, r0, #1
	sbc	r0, r0, r3
.LVL11:
.L23:
.LBE6030:
	.loc 4 229 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE712:
	.fnend
	.size	_ZNK16btCollisionWorld17RayResultCallback14needsCollisionEP17btBroadphaseProxy, .-_ZNK16btCollisionWorld17RayResultCallback14needsCollisionEP17btBroadphaseProxy
	.section	.text._ZN16btCollisionWorld20ConvexResultCallbackD2Ev,"axG",%progbits,_ZN16btCollisionWorld20ConvexResultCallbackD5Ev,comdat
	.align	1
	.weak	_ZN16btCollisionWorld20ConvexResultCallbackD2Ev
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld20ConvexResultCallbackD2Ev, %function
_ZN16btCollisionWorld20ConvexResultCallbackD2Ev:
	.fnstart
.LFB728:
	.loc 4 346 0
	.cfi_startproc
.LVL12:
	.loc 4 346 0
	ldr	r3, .L27
	.loc 4 348 0
	@ sp needed for prologue
	.loc 4 346 0
.LPIC10:
	add	r3, pc
.LBB6031:
	.loc 4 347 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6031:
	.loc 4 348 0
	bx	lr
.L28:
	.align	2
.L27:
	.word	_ZTVN16btCollisionWorld20ConvexResultCallbackE(GOT_PREL)+(.-(.LPIC10+4))
	.cfi_endproc
.LFE728:
	.fnend
	.size	_ZN16btCollisionWorld20ConvexResultCallbackD2Ev, .-_ZN16btCollisionWorld20ConvexResultCallbackD2Ev
	.section	.text._ZNK16btCollisionWorld20ConvexResultCallback14needsCollisionEP17btBroadphaseProxy,"axG",%progbits,_ZNK16btCollisionWorld20ConvexResultCallback14needsCollisionEP17btBroadphaseProxy,comdat
	.align	1
	.weak	_ZNK16btCollisionWorld20ConvexResultCallback14needsCollisionEP17btBroadphaseProxy
	.code	16
	.thumb_func
	.type	_ZNK16btCollisionWorld20ConvexResultCallback14needsCollisionEP17btBroadphaseProxy, %function
_ZNK16btCollisionWorld20ConvexResultCallback14needsCollisionEP17btBroadphaseProxy:
	.fnstart
.LFB732:
	.loc 4 357 0
	.cfi_startproc
.LVL13:
.LBB6032:
	.loc 4 359 0
	ldrh	r2, [r0, #10]
.LBE6032:
	.loc 4 357 0
	mov	r3, r0
.LBB6033:
	.loc 4 359 0
	ldrh	r0, [r1, #4]
.LVL14:
	.loc 4 360 0
	and	r0, r2
	.loc 4 360 0 is_stmt 0 discriminator 2
	lsl	r0, r0, #16
	asr	r0, r0, #16
	.loc 4 360 0
	beq	.L30
	.loc 4 360 0 discriminator 1
	ldrh	r0, [r3, #8]
	ldrh	r2, [r1, #6]
	and	r0, r2
	.loc 4 357 0 is_stmt 1
	sub	r3, r0, #1
	sbc	r0, r0, r3
.LVL15:
.L30:
.LBE6033:
	.loc 4 362 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE732:
	.fnend
	.size	_ZNK16btCollisionWorld20ConvexResultCallback14needsCollisionEP17btBroadphaseProxy, .-_ZNK16btCollisionWorld20ConvexResultCallback14needsCollisionEP17btBroadphaseProxy
	.section	.text._ZN30btConvexPenetrationDepthSolverD2Ev,"axG",%progbits,_ZN30btConvexPenetrationDepthSolverD5Ev,comdat
	.align	1
	.weak	_ZN30btConvexPenetrationDepthSolverD2Ev
	.code	16
	.thumb_func
	.type	_ZN30btConvexPenetrationDepthSolverD2Ev, %function
_ZN30btConvexPenetrationDepthSolverD2Ev:
	.fnstart
.LFB814:
	.file 5 "jni/../../../bullet4droid/jni/src/BulletCollision/NarrowPhaseCollision/btConvexPenetrationDepthSolver.h"
	.loc 5 30 0
	.cfi_startproc
.LVL16:
	.loc 5 30 0
	ldr	r3, .L34
	@ sp needed for prologue
.LPIC12:
	add	r3, pc
.LBB6034:
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6034:
	bx	lr
.L35:
	.align	2
.L34:
	.word	_ZTV30btConvexPenetrationDepthSolver(GOT_PREL)+(.-(.LPIC12+4))
	.cfi_endproc
.LFE814:
	.fnend
	.size	_ZN30btConvexPenetrationDepthSolverD2Ev, .-_ZN30btConvexPenetrationDepthSolverD2Ev
	.section	.text._ZN12btConvexCast10CastResult9DebugDrawEf,"axG",%progbits,_ZN12btConvexCast10CastResult9DebugDrawEf,comdat
	.align	1
	.weak	_ZN12btConvexCast10CastResult9DebugDrawEf
	.code	16
	.thumb_func
	.type	_ZN12btConvexCast10CastResult9DebugDrawEf, %function
_ZN12btConvexCast10CastResult9DebugDrawEf:
	.fnstart
.LFB1173:
	.file 6 "jni/../../../bullet4droid/jni/src/BulletCollision/NarrowPhaseCollision/btConvexCast.h"
	.loc 6 40 0
	.cfi_startproc
.LVL17:
	.loc 6 40 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE1173:
	.fnend
	.size	_ZN12btConvexCast10CastResult9DebugDrawEf, .-_ZN12btConvexCast10CastResult9DebugDrawEf
	.section	.text._ZN12btConvexCast10CastResult15drawCoordSystemERK11btTransform,"axG",%progbits,_ZN12btConvexCast10CastResult15drawCoordSystemERK11btTransform,comdat
	.align	1
	.weak	_ZN12btConvexCast10CastResult15drawCoordSystemERK11btTransform
	.code	16
	.thumb_func
	.type	_ZN12btConvexCast10CastResult15drawCoordSystemERK11btTransform, %function
_ZN12btConvexCast10CastResult15drawCoordSystemERK11btTransform:
	.fnstart
.LFB1174:
	.loc 6 41 0
	.cfi_startproc
.LVL18:
	.loc 6 41 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE1174:
	.fnend
	.size	_ZN12btConvexCast10CastResult15drawCoordSystemERK11btTransform, .-_ZN12btConvexCast10CastResult15drawCoordSystemERK11btTransform
	.section	.text._ZN12btConvexCast10CastResult13reportFailureEii,"axG",%progbits,_ZN12btConvexCast10CastResult13reportFailureEii,comdat
	.align	1
	.weak	_ZN12btConvexCast10CastResult13reportFailureEii
	.code	16
	.thumb_func
	.type	_ZN12btConvexCast10CastResult13reportFailureEii, %function
_ZN12btConvexCast10CastResult13reportFailureEii:
	.fnstart
.LFB1175:
	.loc 6 42 0
	.cfi_startproc
.LVL19:
	.loc 6 42 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE1175:
	.fnend
	.size	_ZN12btConvexCast10CastResult13reportFailureEii, .-_ZN12btConvexCast10CastResult13reportFailureEii
	.section	.text._ZN12btConvexCast10CastResultD2Ev,"axG",%progbits,_ZN12btConvexCast10CastResultD5Ev,comdat
	.align	1
	.weak	_ZN12btConvexCast10CastResultD2Ev
	.code	16
	.thumb_func
	.type	_ZN12btConvexCast10CastResultD2Ev, %function
_ZN12btConvexCast10CastResultD2Ev:
	.fnstart
.LFB1180:
	.loc 6 51 0
	.cfi_startproc
.LVL20:
	.loc 6 51 0
	ldr	r3, .L41
	@ sp needed for prologue
.LPIC14:
	add	r3, pc
.LBB6035:
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6035:
	bx	lr
.L42:
	.align	2
.L41:
	.word	_ZTVN12btConvexCast10CastResultE(GOT_PREL)+(.-(.LPIC14+4))
	.cfi_endproc
.LFE1180:
	.fnend
	.size	_ZN12btConvexCast10CastResultD2Ev, .-_ZN12btConvexCast10CastResultD2Ev
	.section	.text._ZN6btDbvt8ICollideD2Ev,"axG",%progbits,_ZN6btDbvt8ICollideD5Ev,comdat
	.align	1
	.weak	_ZN6btDbvt8ICollideD2Ev
	.code	16
	.thumb_func
	.type	_ZN6btDbvt8ICollideD2Ev, %function
_ZN6btDbvt8ICollideD2Ev:
	.fnstart
.LFB1224:
	.file 7 "jni/../../../bullet4droid/jni/src/BulletCollision/BroadphaseCollision/btDbvt.h"
	.loc 7 229 0
	.cfi_startproc
.LVL21:
	.loc 7 229 0
	ldr	r3, .L45
	@ sp needed for prologue
.LPIC16:
	add	r3, pc
.LBB6036:
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6036:
	bx	lr
.L46:
	.align	2
.L45:
	.word	_ZTVN6btDbvt8ICollideE(GOT_PREL)+(.-(.LPIC16+4))
	.cfi_endproc
.LFE1224:
	.fnend
	.size	_ZN6btDbvt8ICollideD2Ev, .-_ZN6btDbvt8ICollideD2Ev
	.section	.text._ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodeS3_,"axG",%progbits,_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodeS3_,comdat
	.align	1
	.weak	_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodeS3_
	.code	16
	.thumb_func
	.type	_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodeS3_, %function
_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodeS3_:
	.fnstart
.LFB1227:
	.loc 7 230 0
	.cfi_startproc
.LVL22:
	.loc 7 230 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE1227:
	.fnend
	.size	_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodeS3_, .-_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodeS3_
	.section	.text._ZN6btDbvt8ICollide7ProcessEPK10btDbvtNode,"axG",%progbits,_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNode,comdat
	.align	1
	.weak	_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNode
	.code	16
	.thumb_func
	.type	_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNode, %function
_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNode:
	.fnstart
.LFB1228:
	.loc 7 231 0
	.cfi_startproc
.LVL23:
	.loc 7 231 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE1228:
	.fnend
	.size	_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNode, .-_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNode
	.section	.text._ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodef,"axG",%progbits,_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodef,comdat
	.align	1
	.weak	_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodef
	.code	16
	.thumb_func
	.type	_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodef, %function
_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodef:
	.fnstart
.LFB1229:
	.loc 7 232 0
	.cfi_startproc
	.save	{r3, lr}
	push	{r3, lr}
.LCFI0:
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
.LVL24:
	.loc 7 232 0
	ldr	r3, [r0]
	@ sp needed for prologue
	ldr	r3, [r3, #12]
	blx	r3
.LVL25:
	pop	{r3, pc}
	.cfi_endproc
.LFE1229:
	.fnend
	.size	_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodef, .-_ZN6btDbvt8ICollide7ProcessEPK10btDbvtNodef
	.section	.text._ZN6btDbvt8ICollide7DescentEPK10btDbvtNode,"axG",%progbits,_ZN6btDbvt8ICollide7DescentEPK10btDbvtNode,comdat
	.align	1
	.weak	_ZN6btDbvt8ICollide7DescentEPK10btDbvtNode
	.code	16
	.thumb_func
	.type	_ZN6btDbvt8ICollide7DescentEPK10btDbvtNode, %function
_ZN6btDbvt8ICollide7DescentEPK10btDbvtNode:
	.fnstart
.LFB1230:
	.loc 7 233 0
	.cfi_startproc
.LVL26:
	.loc 7 233 0
	mov	r0, #1
.LVL27:
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE1230:
	.fnend
	.size	_ZN6btDbvt8ICollide7DescentEPK10btDbvtNode, .-_ZN6btDbvt8ICollide7DescentEPK10btDbvtNode
	.section	.text._ZN6btDbvt8ICollide9AllLeavesEPK10btDbvtNode,"axG",%progbits,_ZN6btDbvt8ICollide9AllLeavesEPK10btDbvtNode,comdat
	.align	1
	.weak	_ZN6btDbvt8ICollide9AllLeavesEPK10btDbvtNode
	.code	16
	.thumb_func
	.type	_ZN6btDbvt8ICollide9AllLeavesEPK10btDbvtNode, %function
_ZN6btDbvt8ICollide9AllLeavesEPK10btDbvtNode:
	.fnstart
.LFB1231:
	.loc 7 234 0
	.cfi_startproc
.LVL28:
	.loc 7 234 0
	mov	r0, #1
.LVL29:
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE1231:
	.fnend
	.size	_ZN6btDbvt8ICollide9AllLeavesEPK10btDbvtNode, .-_ZN6btDbvt8ICollide9AllLeavesEPK10btDbvtNode
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEENK15LocalInfoAdder214needsCollisionEP17btBroadphaseProxy,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEENK15LocalInfoAdder214needsCollisionEP17btBroadphaseProxy, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEENK15LocalInfoAdder214needsCollisionEP17btBroadphaseProxy:
	.fnstart
.LFB1532:
	.file 8 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionDispatch/btCollisionWorld.cpp"
	.loc 8 459 0
	.cfi_startproc
	.save	{r3, lr}
	push	{r3, lr}
.LCFI1:
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
.LVL30:
	.loc 8 461 0
	ldr	r0, [r0, #20]
.LVL31:
	.loc 8 462 0
	@ sp needed for prologue
	.loc 8 461 0
	ldr	r3, [r0]
	ldr	r3, [r3, #8]
	blx	r3
.LVL32:
	.loc 8 462 0
	pop	{r3, pc}
	.cfi_endproc
.LFE1532:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEENK15LocalInfoAdder214needsCollisionEP17btBroadphaseProxy, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEENK15LocalInfoAdder214needsCollisionEP17btBroadphaseProxy
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder215addSingleResultERNS_14LocalRayResultEb,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder215addSingleResultERNS_14LocalRayResultEb, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder215addSingleResultERNS_14LocalRayResultEb:
	.fnstart
.LFB1533:
	.loc 8 464 0
	.cfi_startproc
	.save	{r0, r1, r4, lr}
	push	{r0, r1, r4, lr}
.LCFI2:
	.cfi_def_cfa_offset 16
	.cfi_offset 0, -16
	.cfi_offset 1, -12
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL33:
.LBB6037:
	.loc 8 467 0
	mov	r3, #1
	neg	r3, r3
	str	r3, [sp]
	.loc 8 468 0
	ldr	r3, [r0, #24]
.LBE6037:
	.loc 8 464 0
	mov	r4, r0
.LBB6038:
	.loc 8 468 0
	str	r3, [sp, #4]
	.loc 8 469 0
	ldr	r3, [r1, #4]
	cmp	r3, #0
	bne	.L54
	.loc 8 470 0
	add	r3, sp, #0
	str	r3, [r1, #4]
.L54:
	.loc 8 472 0
	ldr	r0, [r4, #20]
.LVL34:
.LBE6038:
	.loc 8 475 0
	@ sp needed for prologue
.LBB6039:
	.loc 8 472 0
	ldr	r3, [r0]
	ldr	r3, [r3, #12]
	blx	r3
.LVL35:
	.loc 8 473 0
	ldr	r3, [r4, #20]
	ldr	r3, [r3, #4]
	str	r3, [r4, #4]
.LVL36:
.LBE6039:
	.loc 8 475 0
	pop	{r1, r2, r4, pc}
	.cfi_endproc
.LFE1533:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder215addSingleResultERNS_14LocalRayResultEb, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder215addSingleResultERNS_14LocalRayResultEb
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder2D2Ev,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder2D2Ev, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder2D2Ev:
	.fnstart
.LFB1542:
	.loc 8 448 0
	.cfi_startproc
.LVL37:
.LBB6040:
	.loc 8 448 0
	ldr	r3, .L58
.LBE6040:
	@ sp needed for prologue
.LBB6044:
.LPIC19:
	add	r3, pc
.LBB6041:
.LBB6042:
.LBB6043:
	.loc 4 207 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6043:
.LBE6042:
.LBE6041:
.LBE6044:
	.loc 8 448 0
	bx	lr
.L59:
	.align	2
.L58:
	.word	_ZTVN16btCollisionWorld17RayResultCallbackE(GOT_PREL)+(.-(.LPIC19+4))
	.cfi_endproc
.LFE1542:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder2D2Ev, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder2D2Ev
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN9RayTesterD2Ev,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN9RayTesterD2Ev, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN9RayTesterD2Ev:
	.fnstart
.LFB1547:
	.loc 8 478 0
	.cfi_startproc
.LVL38:
.LBB6045:
	.loc 8 478 0
	ldr	r3, .L63
.LBE6045:
	@ sp needed for prologue
.LBB6049:
.LPIC22:
	add	r3, pc
.LBB6046:
.LBB6047:
.LBB6048:
	.loc 7 229 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6048:
.LBE6047:
.LBE6046:
.LBE6049:
	.loc 8 478 0
	bx	lr
.L64:
	.align	2
.L63:
	.word	_ZTVN6btDbvt8ICollideE(GOT_PREL)+(.-(.LPIC22+4))
	.cfi_endproc
.LFE1547:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN9RayTesterD2Ev, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN9RayTesterD2Ev
	.global	__aeabi_fcmple
	.section	.text._ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallback9reportHitERK9btVector3SE_fii,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallback9reportHitERK9btVector3SE_fii, %function
_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallback9reportHitERK9btVector3SE_fii:
	.fnstart
.LFB1567:
	.loc 8 650 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI3:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL39:
	.pad #68
	sub	sp, sp, #68
.LCFI4:
	.cfi_def_cfa_offset 88
	.loc 8 650 0
	add	r5, r3, #0
.LBB6050:
	.loc 8 653 0
	ldr	r3, [sp, #88]
.LVL40:
.LBE6050:
	.loc 8 650 0
	mov	r7, r0
	str	r1, [sp]
.LBB6059:
	.loc 8 653 0
	str	r3, [sp, #12]
	.loc 8 654 0
	ldr	r3, [sp, #92]
.LBE6059:
	.loc 8 650 0
	str	r2, [sp, #4]
.LBB6060:
	.loc 8 653 0
	add	r6, sp, #12
	.loc 8 654 0
	str	r3, [sp, #16]
.LBB6051:
	.loc 8 655 0
	mov	r3, r0
	add	r3, r3, #212
	ldr	r4, [r3]
	add	r0, r5, #0
.LVL41:
	ldr	r1, [r4, #4]
.LVL42:
	bl	__aeabi_fcmple
.LVL43:
	cmp	r0, #0
	beq	.L66
.LVL44:
.LBB6052:
	.loc 8 663 0
	add	r7, r7, #216
.LVL45:
.LBB6053:
.LBB6054:
.LBB6055:
	.loc 4 321 0
	ldr	r3, [r7]
	ldr	r2, [sp]
	str	r6, [sp, #24]
	str	r3, [sp, #20]
	add	r3, sp, #28
	ldmia	r2!, {r0, r1, r6}
	stmia	r3!, {r0, r1, r6}
.LVL46:
	ldr	r2, [r2]
	str	r2, [r3]
	ldr	r2, [sp, #4]
	add	r3, sp, #44
	ldmia	r2!, {r0, r1, r6}
	stmia	r3!, {r0, r1, r6}
	ldr	r2, [r2]
.LBE6055:
.LBE6054:
.LBE6053:
	.loc 8 668 0
	mov	r0, r4
	add	r1, sp, #20
.LBB6058:
.LBB6057:
.LBB6056:
	.loc 4 321 0
	str	r2, [r3]
	str	r5, [sp, #60]
.LVL47:
.LBE6056:
.LBE6057:
.LBE6058:
	.loc 8 668 0
	ldr	r3, [r4]
	mov	r2, #1
	ldr	r3, [r3, #12]
	blx	r3
.LVL48:
	add	r5, r0, #0
.LVL49:
.L66:
.LBE6052:
.LBE6051:
.LBE6060:
	.loc 8 671 0
	add	sp, sp, #68
.LVL50:
	add	r0, r5, #0
	@ sp needed for prologue
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE1567:
	.fnend
	.size	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallback9reportHitERK9btVector3SE_fii, .-_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallback9reportHitERK9btVector3SE_fii
	.section	.text._ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallback9reportHitE_0RK9btVector3SE_fii,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallback9reportHitE_0RK9btVector3SE_fii, %function
_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallback9reportHitE_0RK9btVector3SE_fii:
	.fnstart
.LFB1575:
	.loc 8 742 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI5:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL51:
	.pad #68
	sub	sp, sp, #68
.LCFI6:
	.cfi_def_cfa_offset 88
	.loc 8 742 0
	add	r5, r3, #0
.LBB6061:
	.loc 8 745 0
	ldr	r3, [sp, #88]
.LVL52:
.LBE6061:
	.loc 8 742 0
	mov	r7, r0
	str	r1, [sp]
.LBB6070:
	.loc 8 745 0
	str	r3, [sp, #12]
	.loc 8 746 0
	ldr	r3, [sp, #92]
.LBE6070:
	.loc 8 742 0
	str	r2, [sp, #4]
.LBB6071:
	.loc 8 745 0
	add	r6, sp, #12
	.loc 8 746 0
	str	r3, [sp, #16]
.LBB6062:
	.loc 8 747 0
	mov	r3, r0
	add	r3, r3, #212
	ldr	r4, [r3]
	add	r0, r5, #0
.LVL53:
	ldr	r1, [r4, #4]
.LVL54:
	bl	__aeabi_fcmple
.LVL55:
	cmp	r0, #0
	beq	.L71
.LVL56:
.LBB6063:
	.loc 8 755 0
	add	r7, r7, #216
.LVL57:
.LBB6064:
.LBB6065:
.LBB6066:
	.loc 4 321 0
	ldr	r3, [r7]
	ldr	r2, [sp]
	str	r6, [sp, #24]
	str	r3, [sp, #20]
	add	r3, sp, #28
	ldmia	r2!, {r0, r1, r6}
	stmia	r3!, {r0, r1, r6}
.LVL58:
	ldr	r2, [r2]
	str	r2, [r3]
	ldr	r2, [sp, #4]
	add	r3, sp, #44
	ldmia	r2!, {r0, r1, r6}
	stmia	r3!, {r0, r1, r6}
	ldr	r2, [r2]
.LBE6066:
.LBE6065:
.LBE6064:
	.loc 8 759 0
	mov	r0, r4
	add	r1, sp, #20
.LBB6069:
.LBB6068:
.LBB6067:
	.loc 4 321 0
	str	r2, [r3]
	str	r5, [sp, #60]
.LVL59:
.LBE6067:
.LBE6068:
.LBE6069:
	.loc 8 759 0
	ldr	r3, [r4]
	mov	r2, #0
	ldr	r3, [r3, #12]
	blx	r3
.LVL60:
	add	r5, r0, #0
.LVL61:
.L71:
.LBE6063:
.LBE6062:
.LBE6071:
	.loc 8 762 0
	add	sp, sp, #68
.LVL62:
	add	r0, r5, #0
	@ sp needed for prologue
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE1575:
	.fnend
	.size	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallback9reportHitE_0RK9btVector3SE_fii, .-_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallback9reportHitE_0RK9btVector3SE_fii
	.section	.text._ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfENK14LocalInfoAdder14needsCollisionEP17btBroadphaseProxy,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfENK14LocalInfoAdder14needsCollisionEP17btBroadphaseProxy, %function
_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfENK14LocalInfoAdder14needsCollisionEP17btBroadphaseProxy:
	.fnstart
.LFB1583:
	.loc 8 803 0
	.cfi_startproc
	.save	{r3, lr}
	push	{r3, lr}
.LCFI7:
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
.LVL63:
	.loc 8 805 0
	ldr	r0, [r0, #12]
.LVL64:
	.loc 8 806 0
	@ sp needed for prologue
	.loc 8 805 0
	ldr	r3, [r0]
	ldr	r3, [r3, #8]
	blx	r3
.LVL65:
	.loc 8 806 0
	pop	{r3, pc}
	.cfi_endproc
.LFE1583:
	.fnend
	.size	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfENK14LocalInfoAdder14needsCollisionEP17btBroadphaseProxy, .-_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfENK14LocalInfoAdder14needsCollisionEP17btBroadphaseProxy
	.section	.text._ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdder15addSingleResultERNS_17LocalConvexResultEb,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdder15addSingleResultERNS_17LocalConvexResultEb, %function
_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdder15addSingleResultERNS_17LocalConvexResultEb:
	.fnstart
.LFB1584:
	.loc 8 807 0
	.cfi_startproc
	.save	{r0, r1, r4, lr}
	push	{r0, r1, r4, lr}
.LCFI8:
	.cfi_def_cfa_offset 16
	.cfi_offset 0, -16
	.cfi_offset 1, -12
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL66:
.LBB6072:
	.loc 8 810 0
	mov	r3, #1
	neg	r3, r3
	str	r3, [sp]
	.loc 8 811 0
	ldr	r3, [r0, #16]
.LBE6072:
	.loc 8 807 0
	mov	r4, r0
.LBB6073:
	.loc 8 811 0
	str	r3, [sp, #4]
	.loc 8 812 0
	ldr	r3, [r1, #4]
	cmp	r3, #0
	bne	.L77
	.loc 8 813 0
	add	r3, sp, #0
	str	r3, [r1, #4]
.L77:
	.loc 8 814 0
	ldr	r0, [r4, #12]
.LVL67:
.LBE6073:
	.loc 8 818 0
	@ sp needed for prologue
.LBB6074:
	.loc 8 814 0
	ldr	r3, [r0]
	ldr	r3, [r3, #12]
	blx	r3
.LVL68:
	.loc 8 815 0
	ldr	r3, [r4, #12]
	ldr	r3, [r3, #4]
	str	r3, [r4, #4]
.LVL69:
.LBE6074:
	.loc 8 818 0
	pop	{r1, r2, r4, pc}
	.cfi_endproc
.LFE1584:
	.fnend
	.size	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdder15addSingleResultERNS_17LocalConvexResultEb, .-_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdder15addSingleResultERNS_17LocalConvexResultEb
	.section	.text._ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdderD2Ev,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdderD2Ev, %function
_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdderD2Ev:
	.fnstart
.LFB1586:
	.loc 8 794 0
	.cfi_startproc
.LVL70:
.LBB6075:
	.loc 8 794 0
	ldr	r3, .L81
.LBE6075:
	@ sp needed for prologue
.LBB6079:
.LPIC25:
	add	r3, pc
.LBB6076:
.LBB6077:
.LBB6078:
	.loc 4 347 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6078:
.LBE6077:
.LBE6076:
.LBE6079:
	.loc 8 794 0
	bx	lr
.L82:
	.align	2
.L81:
	.word	_ZTVN16btCollisionWorld20ConvexResultCallbackE(GOT_PREL)+(.-(.LPIC25+4))
	.cfi_endproc
.LFE1586:
	.fnend
	.size	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdderD2Ev, .-_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdderD2Ev
	.section	.text._ZN19btSingleRayCallbackD2Ev,"axG",%progbits,_ZN19btSingleRayCallbackD5Ev,comdat
	.align	1
	.weak	_ZN19btSingleRayCallbackD2Ev
	.code	16
	.thumb_func
	.type	_ZN19btSingleRayCallbackD2Ev, %function
_ZN19btSingleRayCallbackD2Ev:
	.fnstart
.LFB1601:
	.loc 8 835 0
	.cfi_startproc
.LVL71:
.LBB6080:
.LBB6081:
.LBB6082:
.LBB6083:
	.loc 3 43 0
	ldr	r3, .L87
.LBE6083:
.LBE6082:
.LBE6081:
.LBE6080:
	.loc 8 835 0
	@ sp needed for prologue
.LBB6090:
.LBB6089:
.LBB6088:
.LBB6087:
	.loc 3 43 0
.LPIC27:
	add	r3, pc
.LBB6084:
.LBB6085:
.LBB6086:
	.loc 3 31 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6086:
.LBE6085:
.LBE6084:
.LBE6087:
.LBE6088:
.LBE6089:
.LBE6090:
	.loc 8 835 0
	bx	lr
.L88:
	.align	2
.L87:
	.word	_ZTV24btBroadphaseAabbCallback(GOT_PREL)+(.-(.LPIC27+4))
	.cfi_endproc
.LFE1601:
	.fnend
	.size	_ZN19btSingleRayCallbackD2Ev, .-_ZN19btSingleRayCallbackD2Ev
	.section	.text._ZN21btSingleSweepCallbackD2Ev,"axG",%progbits,_ZN21btSingleSweepCallbackD5Ev,comdat
	.align	1
	.weak	_ZN21btSingleSweepCallbackD2Ev
	.code	16
	.thumb_func
	.type	_ZN21btSingleSweepCallbackD2Ev, %function
_ZN21btSingleSweepCallbackD2Ev:
	.fnstart
.LFB1610:
	.loc 8 932 0
	.cfi_startproc
.LVL72:
.LBB6091:
.LBB6092:
.LBB6093:
.LBB6094:
	.loc 3 43 0
	ldr	r3, .L93
.LBE6094:
.LBE6093:
.LBE6092:
.LBE6091:
	.loc 8 932 0
	@ sp needed for prologue
.LBB6101:
.LBB6100:
.LBB6099:
.LBB6098:
	.loc 3 43 0
.LPIC31:
	add	r3, pc
.LBB6095:
.LBB6096:
.LBB6097:
	.loc 3 31 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6097:
.LBE6096:
.LBE6095:
.LBE6098:
.LBE6099:
.LBE6100:
.LBE6101:
	.loc 8 932 0
	bx	lr
.L94:
	.align	2
.L93:
	.word	_ZTV24btBroadphaseAabbCallback(GOT_PREL)+(.-(.LPIC31+4))
	.cfi_endproc
.LFE1610:
	.fnend
	.size	_ZN21btSingleSweepCallbackD2Ev, .-_ZN21btSingleSweepCallbackD2Ev
	.section	.text._ZN23btBridgedManifoldResultD2Ev,"axG",%progbits,_ZN23btBridgedManifoldResultD5Ev,comdat
	.align	1
	.weak	_ZN23btBridgedManifoldResultD2Ev
	.code	16
	.thumb_func
	.type	_ZN23btBridgedManifoldResultD2Ev, %function
_ZN23btBridgedManifoldResultD2Ev:
	.fnstart
.LFB1622:
	.loc 8 1054 0
	.cfi_startproc
.LVL73:
.LBB6102:
.LBB6103:
.LBB6104:
.LBB6105:
	.loc 2 68 0
	ldr	r3, .L99
.LBE6105:
.LBE6104:
.LBE6103:
.LBE6102:
	.loc 8 1054 0
	@ sp needed for prologue
.LBB6112:
.LBB6111:
.LBB6110:
.LBB6109:
	.loc 2 68 0
.LPIC35:
	add	r3, pc
.LBB6106:
.LBB6107:
.LBB6108:
	.loc 1 34 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6108:
.LBE6107:
.LBE6106:
.LBE6109:
.LBE6110:
.LBE6111:
.LBE6112:
	.loc 8 1054 0
	bx	lr
.L100:
	.align	2
.L99:
	.word	_ZTVN36btDiscreteCollisionDetectorInterface6ResultE(GOT_PREL)+(.-(.LPIC35+4))
	.cfi_endproc
.LFE1622:
	.fnend
	.size	_ZN23btBridgedManifoldResultD2Ev, .-_ZN23btBridgedManifoldResultD2Ev
	.section	.text._ZN23btSingleContactCallbackD2Ev,"axG",%progbits,_ZN23btSingleContactCallbackD5Ev,comdat
	.align	1
	.weak	_ZN23btSingleContactCallbackD2Ev
	.code	16
	.thumb_func
	.type	_ZN23btSingleContactCallbackD2Ev, %function
_ZN23btSingleContactCallbackD2Ev:
	.fnstart
.LFB1627:
	.loc 8 1111 0
	.cfi_startproc
.LVL74:
.LBB6113:
	.loc 8 1111 0
	ldr	r3, .L104
.LBE6113:
	@ sp needed for prologue
.LBB6117:
.LPIC39:
	add	r3, pc
.LBB6114:
.LBB6115:
.LBB6116:
	.loc 3 31 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6116:
.LBE6115:
.LBE6114:
.LBE6117:
	.loc 8 1111 0
	bx	lr
.L105:
	.align	2
.L104:
	.word	_ZTV24btBroadphaseAabbCallback(GOT_PREL)+(.-(.LPIC39+4))
	.cfi_endproc
.LFE1627:
	.fnend
	.size	_ZN23btSingleContactCallbackD2Ev, .-_ZN23btSingleContactCallbackD2Ev
	.section	.text._ZN17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii,"axG",%progbits,_ZN17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii,comdat
	.align	1
	.weak	_ZThn4_N17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii
	.code 32
	.type	_ZThn4_N17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii, %function
_ZThn4_N17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii:
	.fnstart
	ldr	r12, .LTHUMBFUNC0
.LTHUNKPC0:
	add	r12, pc, r12
	sub	r0, r0, #4
	bx	r12
	.align	2
.LTHUMBFUNC0:
	.word	.LTHUNK0-(.LTHUNKPC0+7)
	.fnend
	.size	_ZThn4_N17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii, .-_ZThn4_N17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii
	.align	1
	.weak	_ZN17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii
	.code	16
	.thumb_func
	.type	_ZN17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii, %function
_ZN17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii:
	.fnstart
.LFB1640:
	.loc 8 1205 0
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI9:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL75:
	.loc 8 1207 0
	ldr	r4, [r0]
	.loc 8 1208 0
	@ sp needed for prologue
	.loc 8 1207 0
	ldr	r4, [r4, #8]
	blx	r4
.LVL76:
	.loc 8 1208 0
	pop	{r4, pc}
	.cfi_endproc
.LFE1640:
	.fnend
	.size	_ZN17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii, .-_ZN17DebugDrawcallback28internalProcessTriangleIndexEP9btVector3ii
	.section	.text._ZN23btSingleContactCallbackD0Ev,"axG",%progbits,_ZN23btSingleContactCallbackD5Ev,comdat
	.align	1
	.weak	_ZN23btSingleContactCallbackD0Ev
	.code	16
	.thumb_func
	.type	_ZN23btSingleContactCallbackD0Ev, %function
_ZN23btSingleContactCallbackD0Ev:
	.fnstart
.LFB1629:
	.loc 8 1111 0
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI10:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL77:
.LBB6118:
.LBB6119:
.LBB6120:
	.loc 8 1111 0
	ldr	r3, .L111
.LBE6120:
.LBE6119:
.LBE6118:
	mov	r4, r0
	@ sp needed for prologue
.LBB6126:
.LBB6125:
.LBB6124:
.LPIC42:
	add	r3, pc
.LBB6121:
.LBB6122:
.LBB6123:
	.loc 3 31 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6123:
.LBE6122:
.LBE6121:
.LBE6124:
.LBE6125:
.LBE6126:
	.loc 8 1111 0 discriminator 1
	bl	_ZdlPv
.LVL78:
	.loc 8 1111 0 is_stmt 0
	mov	r0, r4
.LVL79:
	pop	{r4, pc}
.L112:
	.align	2
.L111:
	.word	_ZTV24btBroadphaseAabbCallback(GOT_PREL)+(.-(.LPIC42+4))
	.cfi_endproc
.LFE1629:
	.fnend
	.size	_ZN23btSingleContactCallbackD0Ev, .-_ZN23btSingleContactCallbackD0Ev
	.section	.text._ZN21btSingleSweepCallbackD0Ev,"axG",%progbits,_ZN21btSingleSweepCallbackD5Ev,comdat
	.align	1
	.weak	_ZN21btSingleSweepCallbackD0Ev
	.code	16
	.thumb_func
	.type	_ZN21btSingleSweepCallbackD0Ev, %function
_ZN21btSingleSweepCallbackD0Ev:
	.fnstart
.LFB1612:
	.loc 8 932 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI11:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL80:
.LBB6127:
.LBB6128:
.LBB6129:
.LBB6130:
.LBB6131:
.LBB6132:
	.loc 3 43 0
	ldr	r3, .L118
.LBE6132:
.LBE6131:
.LBE6130:
.LBE6129:
.LBE6128:
.LBE6127:
	.loc 8 932 0
	mov	r4, r0
	@ sp needed for prologue
.LBB6141:
.LBB6140:
.LBB6139:
.LBB6138:
.LBB6137:
.LBB6136:
	.loc 3 43 0
.LPIC45:
	add	r3, pc
.LBB6133:
.LBB6134:
.LBB6135:
	.loc 3 31 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6135:
.LBE6134:
.LBE6133:
.LBE6136:
.LBE6137:
.LBE6138:
.LBE6139:
.LBE6140:
.LBE6141:
	.loc 8 932 0 discriminator 1
	bl	_ZdlPv
.LVL81:
	.loc 8 932 0 is_stmt 0
	mov	r0, r4
.LVL82:
	pop	{r4, pc}
.L119:
	.align	2
.L118:
	.word	_ZTV24btBroadphaseAabbCallback(GOT_PREL)+(.-(.LPIC45+4))
	.cfi_endproc
.LFE1612:
	.fnend
	.size	_ZN21btSingleSweepCallbackD0Ev, .-_ZN21btSingleSweepCallbackD0Ev
	.section	.text._ZN19btSingleRayCallbackD0Ev,"axG",%progbits,_ZN19btSingleRayCallbackD5Ev,comdat
	.align	1
	.weak	_ZN19btSingleRayCallbackD0Ev
	.code	16
	.thumb_func
	.type	_ZN19btSingleRayCallbackD0Ev, %function
_ZN19btSingleRayCallbackD0Ev:
	.fnstart
.LFB1603:
	.loc 8 835 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI12:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL83:
.LBB6142:
.LBB6143:
.LBB6144:
.LBB6145:
.LBB6146:
.LBB6147:
	.loc 3 43 0
	ldr	r3, .L125
.LBE6147:
.LBE6146:
.LBE6145:
.LBE6144:
.LBE6143:
.LBE6142:
	.loc 8 835 0
	mov	r4, r0
	@ sp needed for prologue
.LBB6156:
.LBB6155:
.LBB6154:
.LBB6153:
.LBB6152:
.LBB6151:
	.loc 3 43 0
.LPIC49:
	add	r3, pc
.LBB6148:
.LBB6149:
.LBB6150:
	.loc 3 31 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6150:
.LBE6149:
.LBE6148:
.LBE6151:
.LBE6152:
.LBE6153:
.LBE6154:
.LBE6155:
.LBE6156:
	.loc 8 835 0 discriminator 1
	bl	_ZdlPv
.LVL84:
	.loc 8 835 0 is_stmt 0
	mov	r0, r4
.LVL85:
	pop	{r4, pc}
.L126:
	.align	2
.L125:
	.word	_ZTV24btBroadphaseAabbCallback(GOT_PREL)+(.-(.LPIC49+4))
	.cfi_endproc
.LFE1603:
	.fnend
	.size	_ZN19btSingleRayCallbackD0Ev, .-_ZN19btSingleRayCallbackD0Ev
	.section	.text._ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdderD0Ev,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdderD0Ev, %function
_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdderD0Ev:
	.fnstart
.LFB1588:
	.loc 8 794 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI13:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL86:
.LBB6157:
.LBB6158:
.LBB6159:
	.loc 8 794 0
	ldr	r3, .L131
.LBE6159:
.LBE6158:
.LBE6157:
	mov	r4, r0
	@ sp needed for prologue
.LBB6165:
.LBB6164:
.LBB6163:
.LPIC54:
	add	r3, pc
.LBB6160:
.LBB6161:
.LBB6162:
	.loc 4 347 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6162:
.LBE6161:
.LBE6160:
.LBE6163:
.LBE6164:
.LBE6165:
	.loc 8 794 0 discriminator 1
	bl	_ZdlPv
.LVL87:
	.loc 8 794 0 is_stmt 0
	mov	r0, r4
.LVL88:
	pop	{r4, pc}
.L132:
	.align	2
.L131:
	.word	_ZTVN16btCollisionWorld20ConvexResultCallbackE(GOT_PREL)+(.-(.LPIC54+4))
	.cfi_endproc
.LFE1588:
	.fnend
	.size	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdderD0Ev, .-_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN14LocalInfoAdderD0Ev
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder2D0Ev,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder2D0Ev, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder2D0Ev:
	.fnstart
.LFB1544:
	.loc 8 448 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI14:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL89:
.LBB6166:
.LBB6167:
.LBB6168:
	.loc 8 448 0
	ldr	r3, .L137
.LBE6168:
.LBE6167:
.LBE6166:
	mov	r4, r0
	@ sp needed for prologue
.LBB6174:
.LBB6173:
.LBB6172:
.LPIC57:
	add	r3, pc
.LBB6169:
.LBB6170:
.LBB6171:
	.loc 4 207 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6171:
.LBE6170:
.LBE6169:
.LBE6172:
.LBE6173:
.LBE6174:
	.loc 8 448 0 discriminator 1
	bl	_ZdlPv
.LVL90:
	.loc 8 448 0 is_stmt 0
	mov	r0, r4
.LVL91:
	pop	{r4, pc}
.L138:
	.align	2
.L137:
	.word	_ZTVN16btCollisionWorld17RayResultCallbackE(GOT_PREL)+(.-(.LPIC57+4))
	.cfi_endproc
.LFE1544:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder2D0Ev, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN15LocalInfoAdder2D0Ev
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN9RayTesterD0Ev,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN9RayTesterD0Ev, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN9RayTesterD0Ev:
	.fnstart
.LFB1549:
	.loc 8 478 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI15:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL92:
.LBB6175:
.LBB6176:
.LBB6177:
	.loc 8 478 0
	ldr	r3, .L143
.LBE6177:
.LBE6176:
.LBE6175:
	mov	r4, r0
	@ sp needed for prologue
.LBB6183:
.LBB6182:
.LBB6181:
.LPIC60:
	add	r3, pc
.LBB6178:
.LBB6179:
.LBB6180:
	.loc 7 229 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6180:
.LBE6179:
.LBE6178:
.LBE6181:
.LBE6182:
.LBE6183:
	.loc 8 478 0 discriminator 1
	bl	_ZdlPv
.LVL93:
	.loc 8 478 0 is_stmt 0
	mov	r0, r4
.LVL94:
	pop	{r4, pc}
.L144:
	.align	2
.L143:
	.word	_ZTVN6btDbvt8ICollideE(GOT_PREL)+(.-(.LPIC60+4))
	.cfi_endproc
.LFE1549:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN9RayTesterD0Ev, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN9RayTesterD0Ev
	.section	.text._ZN6btDbvt8ICollideD0Ev,"axG",%progbits,_ZN6btDbvt8ICollideD5Ev,comdat
	.align	1
	.weak	_ZN6btDbvt8ICollideD0Ev
	.code	16
	.thumb_func
	.type	_ZN6btDbvt8ICollideD0Ev, %function
_ZN6btDbvt8ICollideD0Ev:
	.fnstart
.LFB1226:
	.loc 7 229 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI16:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL95:
	.loc 7 229 0
	ldr	r3, .L148
	mov	r4, r0
	@ sp needed for prologue
.LPIC62:
	add	r3, pc
.LBB6184:
.LBB6185:
.LBB6186:
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6186:
.LBE6185:
.LBE6184:
	.loc 7 229 0 is_stmt 0 discriminator 1
	bl	_ZdlPv
.LVL96:
	.loc 7 229 0
	mov	r0, r4
.LVL97:
	pop	{r4, pc}
.L149:
	.align	2
.L148:
	.word	_ZTVN6btDbvt8ICollideE(GOT_PREL)+(.-(.LPIC62+4))
	.cfi_endproc
.LFE1226:
	.fnend
	.size	_ZN6btDbvt8ICollideD0Ev, .-_ZN6btDbvt8ICollideD0Ev
	.section	.text._ZN12btConvexCast10CastResultD0Ev,"axG",%progbits,_ZN12btConvexCast10CastResultD5Ev,comdat
	.align	1
	.weak	_ZN12btConvexCast10CastResultD0Ev
	.code	16
	.thumb_func
	.type	_ZN12btConvexCast10CastResultD0Ev, %function
_ZN12btConvexCast10CastResultD0Ev:
	.fnstart
.LFB1182:
	.loc 6 51 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI17:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL98:
	.loc 6 51 0
	ldr	r3, .L153
	mov	r4, r0
	@ sp needed for prologue
.LPIC64:
	add	r3, pc
.LBB6187:
.LBB6188:
.LBB6189:
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6189:
.LBE6188:
.LBE6187:
	.loc 6 51 0 is_stmt 0 discriminator 1
	bl	_ZdlPv
.LVL99:
	.loc 6 51 0
	mov	r0, r4
.LVL100:
	pop	{r4, pc}
.L154:
	.align	2
.L153:
	.word	_ZTVN12btConvexCast10CastResultE(GOT_PREL)+(.-(.LPIC64+4))
	.cfi_endproc
.LFE1182:
	.fnend
	.size	_ZN12btConvexCast10CastResultD0Ev, .-_ZN12btConvexCast10CastResultD0Ev
	.section	.text._ZN30btConvexPenetrationDepthSolverD0Ev,"axG",%progbits,_ZN30btConvexPenetrationDepthSolverD5Ev,comdat
	.align	1
	.weak	_ZN30btConvexPenetrationDepthSolverD0Ev
	.code	16
	.thumb_func
	.type	_ZN30btConvexPenetrationDepthSolverD0Ev, %function
_ZN30btConvexPenetrationDepthSolverD0Ev:
	.fnstart
.LFB816:
	.loc 5 30 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI18:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL101:
	.loc 5 30 0
	ldr	r3, .L158
	mov	r4, r0
	@ sp needed for prologue
.LPIC66:
	add	r3, pc
.LBB6190:
.LBB6191:
.LBB6192:
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6192:
.LBE6191:
.LBE6190:
	.loc 5 30 0 is_stmt 0 discriminator 1
	bl	_ZdlPv
.LVL102:
	.loc 5 30 0
	mov	r0, r4
.LVL103:
	pop	{r4, pc}
.L159:
	.align	2
.L158:
	.word	_ZTV30btConvexPenetrationDepthSolver(GOT_PREL)+(.-(.LPIC66+4))
	.cfi_endproc
.LFE816:
	.fnend
	.size	_ZN30btConvexPenetrationDepthSolverD0Ev, .-_ZN30btConvexPenetrationDepthSolverD0Ev
	.section	.text._ZN16btCollisionWorld20ConvexResultCallbackD0Ev,"axG",%progbits,_ZN16btCollisionWorld20ConvexResultCallbackD5Ev,comdat
	.align	1
	.weak	_ZN16btCollisionWorld20ConvexResultCallbackD0Ev
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld20ConvexResultCallbackD0Ev, %function
_ZN16btCollisionWorld20ConvexResultCallbackD0Ev:
	.fnstart
.LFB730:
	.loc 4 346 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI19:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL104:
	.loc 4 346 0
	ldr	r3, .L163
	mov	r4, r0
	.loc 4 348 0
	@ sp needed for prologue
	.loc 4 346 0
.LPIC68:
	add	r3, pc
.LBB6193:
.LBB6194:
.LBB6195:
	.loc 4 347 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6195:
.LBE6194:
.LBE6193:
	.loc 4 348 0 discriminator 1
	bl	_ZdlPv
.LVL105:
	.loc 4 348 0 is_stmt 0
	mov	r0, r4
.LVL106:
	pop	{r4, pc}
.L164:
	.align	2
.L163:
	.word	_ZTVN16btCollisionWorld20ConvexResultCallbackE(GOT_PREL)+(.-(.LPIC68+4))
	.cfi_endproc
.LFE730:
	.fnend
	.size	_ZN16btCollisionWorld20ConvexResultCallbackD0Ev, .-_ZN16btCollisionWorld20ConvexResultCallbackD0Ev
	.section	.text._ZN16btCollisionWorld17RayResultCallbackD0Ev,"axG",%progbits,_ZN16btCollisionWorld17RayResultCallbackD5Ev,comdat
	.align	1
	.weak	_ZN16btCollisionWorld17RayResultCallbackD0Ev
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld17RayResultCallbackD0Ev, %function
_ZN16btCollisionWorld17RayResultCallbackD0Ev:
	.fnstart
.LFB707:
	.loc 4 206 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI20:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL107:
	.loc 4 206 0
	ldr	r3, .L168
	mov	r4, r0
	.loc 4 208 0
	@ sp needed for prologue
	.loc 4 206 0
.LPIC70:
	add	r3, pc
.LBB6196:
.LBB6197:
.LBB6198:
	.loc 4 207 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6198:
.LBE6197:
.LBE6196:
	.loc 4 208 0 discriminator 1
	bl	_ZdlPv
.LVL108:
	.loc 4 208 0 is_stmt 0
	mov	r0, r4
.LVL109:
	pop	{r4, pc}
.L169:
	.align	2
.L168:
	.word	_ZTVN16btCollisionWorld17RayResultCallbackE(GOT_PREL)+(.-(.LPIC70+4))
	.cfi_endproc
.LFE707:
	.fnend
	.size	_ZN16btCollisionWorld17RayResultCallbackD0Ev, .-_ZN16btCollisionWorld17RayResultCallbackD0Ev
	.section	.text._ZN23btBroadphaseRayCallbackD0Ev,"axG",%progbits,_ZN23btBroadphaseRayCallbackD5Ev,comdat
	.align	1
	.weak	_ZN23btBroadphaseRayCallbackD0Ev
	.code	16
	.thumb_func
	.type	_ZN23btBroadphaseRayCallbackD0Ev, %function
_ZN23btBroadphaseRayCallbackD0Ev:
	.fnstart
.LFB631:
	.loc 3 43 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI21:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL110:
.LBB6199:
.LBB6200:
.LBB6201:
	.loc 3 43 0
	ldr	r3, .L174
.LBE6201:
.LBE6200:
.LBE6199:
	mov	r4, r0
	@ sp needed for prologue
.LBB6207:
.LBB6206:
.LBB6205:
.LPIC72:
	add	r3, pc
.LBB6202:
.LBB6203:
.LBB6204:
	.loc 3 31 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6204:
.LBE6203:
.LBE6202:
.LBE6205:
.LBE6206:
.LBE6207:
	.loc 3 43 0 discriminator 1
	bl	_ZdlPv
.LVL111:
	.loc 3 43 0 is_stmt 0
	mov	r0, r4
.LVL112:
	pop	{r4, pc}
.L175:
	.align	2
.L174:
	.word	_ZTV24btBroadphaseAabbCallback(GOT_PREL)+(.-(.LPIC72+4))
	.cfi_endproc
.LFE631:
	.fnend
	.size	_ZN23btBroadphaseRayCallbackD0Ev, .-_ZN23btBroadphaseRayCallbackD0Ev
	.section	.text._ZN24btBroadphaseAabbCallbackD0Ev,"axG",%progbits,_ZN24btBroadphaseAabbCallbackD5Ev,comdat
	.align	1
	.weak	_ZN24btBroadphaseAabbCallbackD0Ev
	.code	16
	.thumb_func
	.type	_ZN24btBroadphaseAabbCallbackD0Ev, %function
_ZN24btBroadphaseAabbCallbackD0Ev:
	.fnstart
.LFB627:
	.loc 3 31 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI22:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL113:
	.loc 3 31 0
	ldr	r3, .L179
	mov	r4, r0
	@ sp needed for prologue
.LPIC75:
	add	r3, pc
.LBB6208:
.LBB6209:
.LBB6210:
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6210:
.LBE6209:
.LBE6208:
	.loc 3 31 0 is_stmt 0 discriminator 1
	bl	_ZdlPv
.LVL114:
	.loc 3 31 0
	mov	r0, r4
.LVL115:
	pop	{r4, pc}
.L180:
	.align	2
.L179:
	.word	_ZTV24btBroadphaseAabbCallback(GOT_PREL)+(.-(.LPIC75+4))
	.cfi_endproc
.LFE627:
	.fnend
	.size	_ZN24btBroadphaseAabbCallbackD0Ev, .-_ZN24btBroadphaseAabbCallbackD0Ev
	.section	.text._ZN36btDiscreteCollisionDetectorInterface6ResultD0Ev,"axG",%progbits,_ZN36btDiscreteCollisionDetectorInterface6ResultD5Ev,comdat
	.align	1
	.weak	_ZN36btDiscreteCollisionDetectorInterface6ResultD0Ev
	.code	16
	.thumb_func
	.type	_ZN36btDiscreteCollisionDetectorInterface6ResultD0Ev, %function
_ZN36btDiscreteCollisionDetectorInterface6ResultD0Ev:
	.fnstart
.LFB517:
	.loc 1 34 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI23:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL116:
	.loc 1 34 0
	ldr	r3, .L184
	mov	r4, r0
	@ sp needed for prologue
.LPIC77:
	add	r3, pc
.LBB6211:
.LBB6212:
.LBB6213:
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6213:
.LBE6212:
.LBE6211:
	.loc 1 34 0 is_stmt 0 discriminator 1
	bl	_ZdlPv
.LVL117:
	.loc 1 34 0
	mov	r0, r4
.LVL118:
	pop	{r4, pc}
.L185:
	.align	2
.L184:
	.word	_ZTVN36btDiscreteCollisionDetectorInterface6ResultE(GOT_PREL)+(.-(.LPIC77+4))
	.cfi_endproc
.LFE517:
	.fnend
	.size	_ZN36btDiscreteCollisionDetectorInterface6ResultD0Ev, .-_ZN36btDiscreteCollisionDetectorInterface6ResultD0Ev
	.section	.text._ZN23btBridgedManifoldResultD0Ev,"axG",%progbits,_ZN23btBridgedManifoldResultD5Ev,comdat
	.align	1
	.weak	_ZN23btBridgedManifoldResultD0Ev
	.code	16
	.thumb_func
	.type	_ZN23btBridgedManifoldResultD0Ev, %function
_ZN23btBridgedManifoldResultD0Ev:
	.fnstart
.LFB1624:
	.loc 8 1054 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI24:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL119:
.LBB6214:
.LBB6215:
.LBB6216:
.LBB6217:
.LBB6218:
.LBB6219:
	.loc 2 68 0
	ldr	r3, .L191
.LBE6219:
.LBE6218:
.LBE6217:
.LBE6216:
.LBE6215:
.LBE6214:
	.loc 8 1054 0
	mov	r4, r0
	@ sp needed for prologue
.LBB6228:
.LBB6227:
.LBB6226:
.LBB6225:
.LBB6224:
.LBB6223:
	.loc 2 68 0
.LPIC79:
	add	r3, pc
.LBB6220:
.LBB6221:
.LBB6222:
	.loc 1 34 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LBE6222:
.LBE6221:
.LBE6220:
.LBE6223:
.LBE6224:
.LBE6225:
.LBE6226:
.LBE6227:
.LBE6228:
	.loc 8 1054 0 discriminator 1
	bl	_ZdlPv
.LVL120:
	.loc 8 1054 0 is_stmt 0
	mov	r0, r4
.LVL121:
	pop	{r4, pc}
.L192:
	.align	2
.L191:
	.word	_ZTVN36btDiscreteCollisionDetectorInterface6ResultE(GOT_PREL)+(.-(.LPIC79+4))
	.cfi_endproc
.LFE1624:
	.fnend
	.size	_ZN23btBridgedManifoldResultD0Ev, .-_ZN23btBridgedManifoldResultD0Ev
	.section	.text._ZN16btCollisionWorldD2Ev,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorldD2Ev
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorldD2Ev, %function
_ZN16btCollisionWorldD2Ev:
	.fnstart
.LFB1490:
	.loc 8 78 0 is_stmt 1
	.cfi_startproc
	.save	{r3, r4, r5, r6, r7, lr}
	push	{r3, r4, r5, r6, r7, lr}
.LCFI25:
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL122:
	.loc 8 78 0
	ldr	r3, .L201
	mov	r4, r0
.LBB6229:
.LBB6230:
.LBB6231:
	.loc 8 83 0
	mov	r5, #0
.LBE6231:
.LBE6230:
.LBE6229:
	.loc 8 78 0
.LPIC83:
	add	r3, pc
.LBB6257:
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
.LVL123:
.LBB6242:
.LBB6241:
	.loc 8 83 0
	b	.L194
.LVL124:
.L196:
.LBB6232:
	.loc 8 85 0
	lsl	r3, r5, #2
	ldr	r6, [r0, r3]
.LVL125:
.LBB6233:
.LBB6234:
	.file 9 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionDispatch/btCollisionObject.h"
	.loc 9 309 0
	add	r6, r6, #188
	ldr	r7, [r6]
.LBE6234:
.LBE6233:
	.loc 8 88 0
	cmp	r7, #0
	beq	.L195
.LVL126:
.LBB6235:
.LBB6236:
	.loc 4 122 0
	ldr	r0, [r4, #68]
.LVL127:
.LBE6236:
.LBE6235:
	.loc 8 93 0
	ldr	r3, [r0]
.LVL128:
	ldr	r3, [r3, #36]
	blx	r3
	ldr	r3, [r0]
	ldr	r2, [r4, #24]
	mov	r1, r7
	ldr	r3, [r3, #40]
	blx	r3
.LVL129:
.LBB6237:
.LBB6238:
	.loc 4 122 0
	ldr	r0, [r4, #68]
.LBE6238:
.LBE6237:
	.loc 8 94 0
	ldr	r2, [r4, #24]
	mov	r1, r7
	ldr	r3, [r0]
	ldr	r3, [r3, #12]
	blx	r3
.LVL130:
.LBB6239:
.LBB6240:
	.loc 9 319 0
	mov	r3, #0
	str	r3, [r6]
.LVL131:
.L195:
.LBE6240:
.LBE6239:
.LBE6232:
	.loc 8 83 0
	add	r5, r5, #1
.LVL132:
.L194:
	.loc 8 83 0 is_stmt 0 discriminator 1
	ldr	r3, [r4, #8]
	ldr	r0, [r4, #16]
	cmp	r5, r3
	blt	.L196
.LVL133:
.LBE6241:
.LBE6242:
.LBB6243:
.LBB6244:
.LBB6245:
.LBB6246:
.LBB6247:
	.file 10 "jni/../../../bullet4droid/jni/src/LinearMath/btAlignedObjectArray.h"
	.loc 10 111 0 is_stmt 1
	cmp	r0, #0
	beq	.L197
	.loc 10 113 0
	ldrb	r3, [r4, #20]
	cmp	r3, #0
	beq	.L197
.LVL134:
.LBB6248:
.LBB6249:
	.file 11 "jni/../../../bullet4droid/jni/src/LinearMath/btAlignedAllocator.h"
	.loc 11 90 0
	bl	_Z21btAlignedFreeInternalPv
.LVL135:
.L197:
.LBE6249:
.LBE6248:
.LBE6247:
.LBE6246:
.LBB6250:
.LBB6251:
	.loc 10 88 0
	mov	r3, #1
	strb	r3, [r4, #20]
	.loc 10 89 0
	mov	r3, #0
.LBE6251:
.LBE6250:
.LBE6245:
.LBE6244:
.LBE6243:
.LBE6257:
	.loc 8 100 0
	mov	r0, r4
.LBB6258:
.LBB6256:
.LBB6255:
.LBB6254:
.LBB6253:
.LBB6252:
	.loc 10 89 0
	str	r3, [r4, #16]
	.loc 10 90 0
	str	r3, [r4, #8]
	.loc 10 91 0
	str	r3, [r4, #12]
.LBE6252:
.LBE6253:
.LBE6254:
.LBE6255:
.LBE6256:
.LBE6258:
	.loc 8 100 0
	@ sp needed for prologue
.LVL136:
.LVL137:
	pop	{r3, r4, r5, r6, r7, pc}
.L202:
	.align	2
.L201:
	.word	_ZTV16btCollisionWorld(GOT_PREL)+(.-(.LPIC83+4))
	.cfi_endproc
.LFE1490:
	.fnend
	.size	_ZN16btCollisionWorldD2Ev, .-_ZN16btCollisionWorldD2Ev
	.section	.text._ZN16btCollisionWorldD0Ev,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorldD0Ev
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorldD0Ev, %function
_ZN16btCollisionWorldD0Ev:
	.fnstart
.LFB1492:
	.loc 8 78 0
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI26:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL138:
	.loc 8 78 0
	mov	r4, r0
	.loc 8 100 0
	bl	_ZN16btCollisionWorldD1Ev
.LVL139:
	.loc 8 100 0 is_stmt 0 discriminator 1
	mov	r0, r4
	bl	_ZdlPv
	.loc 8 100 0
	@ sp needed for prologue
	mov	r0, r4
.LVL140:
	pop	{r4, pc}
	.cfi_endproc
.LFE1492:
	.fnend
	.size	_ZN16btCollisionWorldD0Ev, .-_ZN16btCollisionWorldD0Ev
	.section	.text._ZN17DebugDrawcallbackD1Ev,"axG",%progbits,_ZN17DebugDrawcallbackD1Ev,comdat
	.align	1
	.weak	_ZThn4_N17DebugDrawcallbackD1Ev
	.code 32
	.type	_ZThn4_N17DebugDrawcallbackD1Ev, %function
_ZThn4_N17DebugDrawcallbackD1Ev:
	.fnstart
	ldr	r12, .LTHUMBFUNC1
.LTHUNKPC1:
	add	r12, pc, r12
	sub	r0, r0, #4
	bx	r12
	.align	2
.LTHUMBFUNC1:
	.word	.LTHUNK1-(.LTHUNKPC1+7)
	.fnend
	.size	_ZThn4_N17DebugDrawcallbackD1Ev, .-_ZThn4_N17DebugDrawcallbackD1Ev
	.section	.text._ZN17DebugDrawcallbackD2Ev,"axG",%progbits,_ZN17DebugDrawcallbackD5Ev,comdat
	.align	1
	.weak	_ZN17DebugDrawcallbackD2Ev
	.code	16
	.thumb_func
	.type	_ZN17DebugDrawcallbackD2Ev, %function
_ZN17DebugDrawcallbackD2Ev:
	.fnstart
.LFB1644:
	.loc 8 1190 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI27:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL141:
	.loc 8 1190 0
	ldr	r3, .L207
	mov	r4, r0
	@ sp needed for prologue
.LPIC85:
	add	r3, pc
.LBB6259:
	ldr	r3, [r3]
	mov	r2, r3
	add	r2, r2, #8
	add	r3, r3, #32
	str	r2, [r0]
	str	r3, [r0, #4]
	add	r0, r0, #4
.LVL142:
	bl	_ZN31btInternalTriangleIndexCallbackD2Ev
	mov	r0, r4
	bl	_ZN18btTriangleCallbackD2Ev
.LBE6259:
	mov	r0, r4
.LVL143:
	pop	{r4, pc}
.L208:
	.align	2
.L207:
	.word	_ZTV17DebugDrawcallback(GOT_PREL)+(.-(.LPIC85+4))
	.cfi_endproc
.LFE1644:
	.fnend
	.size	_ZN17DebugDrawcallbackD2Ev, .-_ZN17DebugDrawcallbackD2Ev
	.section	.text._ZN17DebugDrawcallbackD0Ev,"axG",%progbits,_ZN17DebugDrawcallbackD0Ev,comdat
	.align	1
	.weak	_ZThn4_N17DebugDrawcallbackD0Ev
	.code 32
	.type	_ZThn4_N17DebugDrawcallbackD0Ev, %function
_ZThn4_N17DebugDrawcallbackD0Ev:
	.fnstart
	ldr	r12, .LTHUMBFUNC2
.LTHUNKPC2:
	add	r12, pc, r12
	sub	r0, r0, #4
	bx	r12
	.align	2
.LTHUMBFUNC2:
	.word	.LTHUNK2-(.LTHUNKPC2+7)
	.fnend
	.size	_ZThn4_N17DebugDrawcallbackD0Ev, .-_ZThn4_N17DebugDrawcallbackD0Ev
	.align	1
	.weak	_ZN17DebugDrawcallbackD0Ev
	.code	16
	.thumb_func
	.type	_ZN17DebugDrawcallbackD0Ev, %function
_ZN17DebugDrawcallbackD0Ev:
	.fnstart
.LFB1646:
	.loc 8 1190 0
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI28:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL144:
	.loc 8 1190 0
	mov	r4, r0
	bl	_ZN17DebugDrawcallbackD1Ev
.LVL145:
	.loc 8 1190 0 is_stmt 0 discriminator 1
	mov	r0, r4
	bl	_ZdlPv
	.loc 8 1190 0
	@ sp needed for prologue
	mov	r0, r4
.LVL146:
	pop	{r4, pc}
	.cfi_endproc
.LFE1646:
	.fnend
	.size	_ZN17DebugDrawcallbackD0Ev, .-_ZN17DebugDrawcallbackD0Ev
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD2Ev,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD2Ev, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD2Ev:
	.fnstart
.LFB1518:
	.loc 8 338 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI29:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL147:
.LBB6260:
	.loc 8 338 0
	ldr	r3, .L214
.LBE6260:
	mov	r4, r0
	@ sp needed for prologue
.LBB6264:
.LPIC88:
	add	r3, pc
.LBB6261:
.LBB6262:
.LBB6263:
	.file 12 "jni/../../../bullet4droid/jni/src/BulletCollision/NarrowPhaseCollision/btRaycastCallback.h"
	.loc 12 24 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
	bl	_ZN18btTriangleCallbackD2Ev
.LVL148:
.LBE6263:
.LBE6262:
.LBE6261:
.LBE6264:
	.loc 8 338 0
	mov	r0, r4
.LVL149:
	pop	{r4, pc}
.L215:
	.align	2
.L214:
	.word	_ZTV25btTriangleRaycastCallback(GOT_PREL)+(.-(.LPIC88+4))
	.cfi_endproc
.LFE1518:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD2Ev, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD2Ev
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD0Ev,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD0Ev, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD0Ev:
	.fnstart
.LFB1520:
	.loc 8 338 0
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI30:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL150:
	.loc 8 338 0
	mov	r4, r0
	bl	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD1Ev
.LVL151:
	.loc 8 338 0 is_stmt 0 discriminator 1
	mov	r0, r4
	bl	_ZdlPv
	.loc 8 338 0
	@ sp needed for prologue
	mov	r0, r4
.LVL152:
	pop	{r4, pc}
	.cfi_endproc
.LFE1520:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD0Ev, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD0Ev
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD2E_0v,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD2E_0v, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD2E_0v:
	.fnstart
.LFB1526:
	.loc 8 393 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI31:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL153:
.LBB6265:
	.loc 8 393 0
	ldr	r3, .L221
.LBE6265:
	mov	r4, r0
	@ sp needed for prologue
.LBB6269:
.LPIC91:
	add	r3, pc
.LBB6266:
.LBB6267:
.LBB6268:
	.loc 12 24 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
	bl	_ZN18btTriangleCallbackD2Ev
.LVL154:
.LBE6268:
.LBE6267:
.LBE6266:
.LBE6269:
	.loc 8 393 0
	mov	r0, r4
.LVL155:
	pop	{r4, pc}
.L222:
	.align	2
.L221:
	.word	_ZTV25btTriangleRaycastCallback(GOT_PREL)+(.-(.LPIC91+4))
	.cfi_endproc
.LFE1526:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD2E_0v, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD2E_0v
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD0E_0v,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD0E_0v, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD0E_0v:
	.fnstart
.LFB1528:
	.loc 8 393 0
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI32:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL156:
	.loc 8 393 0
	mov	r4, r0
	bl	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD1E_0v
.LVL157:
	.loc 8 393 0 is_stmt 0 discriminator 1
	mov	r0, r4
	bl	_ZdlPv
	.loc 8 393 0
	@ sp needed for prologue
	mov	r0, r4
.LVL158:
	pop	{r4, pc}
	.cfi_endproc
.LFE1528:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD0E_0v, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallbackD0E_0v
	.section	.text._ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD2Ev,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD2Ev, %function
_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD2Ev:
	.fnstart
.LFB1569:
	.loc 8 634 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI33:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL159:
.LBB6270:
	.loc 8 634 0
	ldr	r3, .L228
.LBE6270:
	mov	r4, r0
	@ sp needed for prologue
.LBB6274:
.LPIC94:
	add	r3, pc
.LBB6271:
.LBB6272:
.LBB6273:
	.loc 12 53 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
	bl	_ZN18btTriangleCallbackD2Ev
.LVL160:
.LBE6273:
.LBE6272:
.LBE6271:
.LBE6274:
	.loc 8 634 0
	mov	r0, r4
.LVL161:
	pop	{r4, pc}
.L229:
	.align	2
.L228:
	.word	_ZTV28btTriangleConvexcastCallback(GOT_PREL)+(.-(.LPIC94+4))
	.cfi_endproc
.LFE1569:
	.fnend
	.size	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD2Ev, .-_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD2Ev
	.section	.text._ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD0Ev,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD0Ev, %function
_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD0Ev:
	.fnstart
.LFB1571:
	.loc 8 634 0
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI34:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL162:
	.loc 8 634 0
	mov	r4, r0
	bl	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD1Ev
.LVL163:
	.loc 8 634 0 is_stmt 0 discriminator 1
	mov	r0, r4
	bl	_ZdlPv
	.loc 8 634 0
	@ sp needed for prologue
	mov	r0, r4
.LVL164:
	pop	{r4, pc}
	.cfi_endproc
.LFE1571:
	.fnend
	.size	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD0Ev, .-_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD0Ev
	.section	.text._ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD2E_0v,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD2E_0v, %function
_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD2E_0v:
	.fnstart
.LFB1577:
	.loc 8 726 0 is_stmt 1
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI35:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL165:
.LBB6275:
	.loc 8 726 0
	ldr	r3, .L235
.LBE6275:
	mov	r4, r0
	@ sp needed for prologue
.LBB6279:
.LPIC97:
	add	r3, pc
.LBB6276:
.LBB6277:
.LBB6278:
	.loc 12 53 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [r0]
	bl	_ZN18btTriangleCallbackD2Ev
.LVL166:
.LBE6278:
.LBE6277:
.LBE6276:
.LBE6279:
	.loc 8 726 0
	mov	r0, r4
.LVL167:
	pop	{r4, pc}
.L236:
	.align	2
.L235:
	.word	_ZTV28btTriangleConvexcastCallback(GOT_PREL)+(.-(.LPIC97+4))
	.cfi_endproc
.LFE1577:
	.fnend
	.size	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD2E_0v, .-_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD2E_0v
	.section	.text._ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD0E_0v,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD0E_0v, %function
_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD0E_0v:
	.fnstart
.LFB1579:
	.loc 8 726 0
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI36:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL168:
	.loc 8 726 0
	mov	r4, r0
	bl	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD1E_0v
.LVL169:
	.loc 8 726 0 is_stmt 0 discriminator 1
	mov	r0, r4
	bl	_ZdlPv
	.loc 8 726 0
	@ sp needed for prologue
	mov	r0, r4
.LVL170:
	pop	{r4, pc}
	.cfi_endproc
.LFE1579:
	.fnend
	.size	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD0E_0v, .-_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD0E_0v
	.section	.text._ZN23btSingleContactCallback7processEPK17btBroadphaseProxy,"axG",%progbits,_ZN23btSingleContactCallback7processEPK17btBroadphaseProxy,comdat
	.align	1
	.weak	_ZN23btSingleContactCallback7processEPK17btBroadphaseProxy
	.code	16
	.thumb_func
	.type	_ZN23btSingleContactCallback7processEPK17btBroadphaseProxy, %function
_ZN23btSingleContactCallback7processEPK17btBroadphaseProxy:
	.fnstart
.LFB1620:
	.loc 8 1126 0 is_stmt 1
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI37:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL171:
.LBB6280:
	.loc 8 1128 0
	ldr	r4, [r1]
.LVL172:
	.loc 8 1129 0
	ldr	r3, [r0, #4]
.LBE6280:
	.loc 8 1126 0
	.pad #100
	sub	sp, sp, #100
.LCFI38:
	.cfi_def_cfa_offset 120
	.loc 8 1126 0
	mov	r5, r0
.LBB6335:
	.loc 8 1129 0
	cmp	r4, r3
	beq	.L245
.LBB6281:
	.loc 8 1133 0
	ldr	r0, [r0, #12]
.LVL173:
.LBB6282:
.LBB6283:
	.loc 9 309 0
	mov	r2, r4
	add	r2, r2, #188
.LBE6283:
.LBE6282:
	.loc 8 1133 0
	ldr	r3, [r0]
	ldr	r1, [r2]
.LVL174:
	ldr	r3, [r3, #8]
	blx	r3
	cmp	r0, #0
	beq	.L245
.LBB6284:
	.loc 8 1135 0
	ldr	r2, [r5, #4]
.LVL175:
.LBB6285:
.LBB6286:
.LBB6287:
	.file 13 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionDispatch/btCollisionObjectWrapper.h"
	.loc 13 35 0
	str	r4, [sp, #44]
.LBE6287:
.LBE6286:
.LBE6285:
.LBB6294:
.LBB6295:
	.loc 9 216 0
	mov	r3, r2
	add	r3, r3, #192
	ldr	r1, [r3]
.LVL176:
.LBE6295:
.LBE6294:
.LBB6296:
.LBB6297:
.LBB6298:
	.loc 13 35 0
	str	r2, [sp, #20]
	.loc 8 1135 0
	add	r2, r2, #4
	.loc 13 35 0
	str	r2, [sp, #24]
	mov	r2, #1
	neg	r2, r2
	str	r2, [sp, #28]
	str	r2, [sp, #32]
.LVL177:
.LBE6298:
.LBE6297:
.LBE6296:
.LBB6305:
.LBB6291:
.LBB6288:
	str	r2, [sp, #52]
	str	r2, [sp, #56]
.LBE6288:
.LBE6291:
.LBE6305:
.LBB6306:
.LBB6302:
.LBB6299:
	str	r1, [sp, #16]
.LBE6299:
.LBE6302:
.LBE6306:
.LBB6307:
.LBB6308:
	.loc 4 133 0
	ldr	r2, [r5, #8]
.LBE6308:
.LBE6307:
.LBB6310:
.LBB6311:
	.loc 9 216 0
	mov	r1, r4
	add	r1, r1, #192
	ldr	r1, [r1]
.LVL178:
.LBE6311:
.LBE6310:
.LBB6312:
.LBB6309:
	.loc 4 133 0
	ldr	r0, [r2, #24]
.LBE6309:
.LBE6312:
.LBB6313:
.LBB6303:
.LBB6300:
	.loc 13 35 0
	mov	r3, #0
.LVL179:
.LBE6300:
.LBE6303:
.LBE6313:
.LBB6314:
.LBB6292:
.LBB6289:
	.loc 8 1136 0
	add	r4, r4, #4
.LVL180:
	.loc 13 35 0
	str	r1, [sp, #40]
	str	r4, [sp, #48]
.LBE6289:
.LBE6292:
.LBE6314:
.LBB6315:
.LBB6304:
.LBB6301:
	str	r3, [sp, #12]
.LBE6301:
.LBE6304:
.LBE6315:
.LBB6316:
.LBB6293:
.LBB6290:
	str	r3, [sp, #36]
.LBE6290:
.LBE6293:
.LBE6316:
	.loc 8 1138 0
	ldr	r2, [r0]
	add	r1, sp, #12
.LVL181:
	ldr	r4, [r2, #8]
	add	r2, sp, #36
	blx	r4
.LVL182:
.LBB6317:
	.loc 8 1139 0
	sub	r6, r0, #0
	beq	.L245
.LBB6318:
.LBB6319:
.LBB6320:
.LBB6321:
	.loc 8 1061 0
	add	r4, sp, #60
	mov	r0, r4
	add	r1, sp, #12
	add	r2, sp, #36
.LBE6321:
.LBE6320:
.LBE6319:
	.loc 8 1141 0
	ldr	r7, [r5, #12]
.LVL183:
.LBB6328:
.LBB6325:
.LBB6322:
	.loc 8 1061 0
	bl	_ZN16btManifoldResultC2EPK24btCollisionObjectWrapperS2_
.LVL184:
	ldr	r3, .L246
	str	r7, [r4, #32]
.LVL185:
.LBE6322:
.LBE6325:
.LBE6328:
	.loc 8 1144 0
	add	r1, sp, #12
.LBB6329:
.LBB6326:
.LBB6323:
	.loc 8 1061 0
.LPIC99:
	add	r3, pc
	ldr	r3, [r3]
.LBE6323:
.LBE6326:
.LBE6329:
	.loc 8 1144 0
	mov	r0, r6
.LBB6330:
.LBB6327:
.LBB6324:
	.loc 8 1061 0
	add	r3, r3, #8
	str	r3, [sp, #60]
.LBE6324:
.LBE6327:
.LBE6330:
	.loc 8 1144 0
	ldr	r2, [r6]
	ldr	r3, [r5, #8]
	str	r4, [sp]
	ldr	r4, [r2, #8]
.LVL186:
	add	r3, r3, #28
	add	r2, sp, #36
	blx	r4
.LVL187:
	.loc 8 1146 0
	ldr	r3, [r6]
	mov	r0, r6
	ldr	r3, [r3]
	blx	r3
.LVL188:
.LBB6331:
.LBB6332:
	.loc 4 133 0
	ldr	r3, [r5, #8]
.LBE6332:
.LBE6331:
	.loc 8 1147 0
	mov	r1, r6
.LBB6334:
.LBB6333:
	.loc 4 133 0
	ldr	r0, [r3, #24]
.LBE6333:
.LBE6334:
	.loc 8 1147 0
	ldr	r3, [r0]
	ldr	r3, [r3, #60]
	blx	r3
.LVL189:
.L245:
.LBE6318:
.LBE6317:
.LBE6284:
.LBE6281:
.LBE6335:
	.loc 8 1151 0
	add	sp, sp, #100
	mov	r0, #1
	@ sp needed for prologue
.LVL190:
	pop	{r4, r5, r6, r7, pc}
.L247:
	.align	2
.L246:
	.word	_ZTV23btBridgedManifoldResult(GOT_PREL)+(.-(.LPIC99+4))
	.cfi_endproc
.LFE1620:
	.fnend
	.size	_ZN23btSingleContactCallback7processEPK17btBroadphaseProxy, .-_ZN23btSingleContactCallback7processEPK17btBroadphaseProxy
	.section	.text._ZN16btCollisionWorld33performDiscreteCollisionDetectionEv,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorld33performDiscreteCollisionDetectionEv
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld33performDiscreteCollisionDetectionEv, %function
_ZN16btCollisionWorld33performDiscreteCollisionDetectionEv:
	.fnstart
.LFB1497:
	.loc 8 215 0
	.cfi_startproc
	.save	{r4, r5, r6, lr}
	push	{r4, r5, r6, lr}
.LCFI39:
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
.LVL191:
	.loc 8 215 0
	mov	r4, r0
.LBB6336:
.LBB6337:
.LBB6338:
.LBB6339:
	.file 14 "jni/../../../bullet4droid/jni/src/LinearMath/btQuickprof.h"
	.loc 14 181 0
	ldr	r0, .L254
.LVL192:
.LPIC100:
	add	r0, pc
	bl	_ZN15CProfileManager13Start_ProfileEPKc
.LVL193:
.LBE6339:
.LBE6338:
.LBE6337:
	.loc 8 220 0
	ldr	r3, [r4]
	mov	r0, r4
	ldr	r3, [r3, #8]
	blx	r3
	.loc 8 222 0
	ldr	r3, [r4]
	mov	r0, r4
	ldr	r3, [r3, #12]
	blx	r3
.LVL194:
.LBB6340:
.LBB6341:
.LBB6342:
.LBB6343:
	.loc 14 181 0
	ldr	r0, .L254+4
.LBE6343:
.LBE6342:
.LBE6341:
.LBE6340:
.LBB6350:
.LBB6351:
	.loc 4 133 0
	ldr	r5, [r4, #24]
.LVL195:
.LBE6351:
.LBE6350:
.LBB6352:
.LBB6346:
.LBB6345:
.LBB6344:
	.loc 14 181 0
.LPIC101:
	add	r0, pc
	bl	_ZN15CProfileManager13Start_ProfileEPKc
.LBE6344:
.LBE6345:
.LBE6346:
	.loc 8 227 0
	cmp	r5, #0
	beq	.L251
	.loc 8 228 0
	ldr	r3, [r5]
	ldr	r0, [r4, #68]
	ldr	r6, [r3, #32]
	ldr	r3, [r0]
	ldr	r3, [r3, #36]
	blx	r3
	.loc 8 218 0
	mov	r2, r4
	.loc 8 228 0
	mov	r1, r0
	.loc 8 218 0
	add	r2, r2, #28
	.loc 8 228 0
	ldr	r3, [r4, #24]
	mov	r0, r5
	blx	r6
.L251:
.LBB6347:
.LBB6348:
.LBB6349:
	.loc 14 186 0
	bl	_ZN15CProfileManager12Stop_ProfileEv
.LBE6349:
.LBE6348:
.LBE6347:
.LBE6352:
.LBE6336:
	.loc 8 231 0
	@ sp needed for prologue
.LBB6356:
.LBB6353:
.LBB6354:
.LBB6355:
	.loc 14 186 0
	bl	_ZN15CProfileManager12Stop_ProfileEv
.LVL196:
.LBE6355:
.LBE6354:
.LBE6353:
.LBE6356:
	.loc 8 231 0
	pop	{r4, r5, r6, pc}
.L255:
	.align	2
.L254:
	.word	.LC0-(.LPIC100+4)
	.word	.LC1-(.LPIC101+4)
	.cfi_endproc
.LFE1497:
	.fnend
	.size	_ZN16btCollisionWorld33performDiscreteCollisionDetectionEv, .-_ZN16btCollisionWorld33performDiscreteCollisionDetectionEv
	.section	.text._ZN16btCollisionWorld23computeOverlappingPairsEv,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorld23computeOverlappingPairsEv
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld23computeOverlappingPairsEv, %function
_ZN16btCollisionWorld23computeOverlappingPairsEv:
	.fnstart
.LFB1496:
	.loc 8 209 0
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI40:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL197:
	.loc 8 209 0
	mov	r4, r0
.LBB6357:
.LBB6358:
.LBB6359:
.LBB6360:
	.loc 14 181 0
	ldr	r0, .L259
.LVL198:
.LBE6360:
.LBE6359:
.LBE6358:
.LBE6357:
	.loc 8 212 0
	@ sp needed for prologue
.LBB6367:
.LBB6363:
.LBB6362:
.LBB6361:
	.loc 14 181 0
.LPIC102:
	add	r0, pc
	bl	_ZN15CProfileManager13Start_ProfileEPKc
.LBE6361:
.LBE6362:
.LBE6363:
	.loc 8 211 0
	ldr	r0, [r4, #68]
	ldr	r1, [r4, #24]
	ldr	r3, [r0]
	ldr	r3, [r3, #32]
	blx	r3
.LBB6364:
.LBB6365:
.LBB6366:
	.loc 14 186 0
	bl	_ZN15CProfileManager12Stop_ProfileEv
.LVL199:
.LBE6366:
.LBE6365:
.LBE6364:
.LBE6367:
	.loc 8 212 0
	pop	{r4, pc}
.L260:
	.align	2
.L259:
	.word	.LC2-(.LPIC102+4)
	.cfi_endproc
.LFE1496:
	.fnend
	.size	_ZN16btCollisionWorld23computeOverlappingPairsEv, .-_ZN16btCollisionWorld23computeOverlappingPairsEv
	.global	__aeabi_fadd
	.section	.text._ZN9btVector3pLERKS_,"axG",%progbits,_ZN9btVector3pLERKS_,comdat
	.align	1
	.weak	_ZN9btVector3pLERKS_
	.code	16
	.thumb_func
	.type	_ZN9btVector3pLERKS_, %function
_ZN9btVector3pLERKS_:
	.fnstart
.LFB84:
	.file 15 "jni/../../../bullet4droid/jni/src/LinearMath/btVector3.h"
	.loc 15 163 0
	.cfi_startproc
	.save	{r3, r4, r5, lr}
	push	{r3, r4, r5, lr}
.LCFI41:
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	.cfi_offset 4, -12
	.cfi_offset 5, -8
	.cfi_offset 14, -4
.LVL200:
	.loc 15 163 0
	mov	r4, r0
	mov	r5, r1
	.loc 15 170 0
	ldr	r0, [r0]
.LVL201:
	ldr	r1, [r1]
.LVL202:
	bl	__aeabi_fadd
	str	r0, [r4]
	.loc 15 171 0
	ldr	r1, [r5, #4]
	ldr	r0, [r4, #4]
	bl	__aeabi_fadd
	str	r0, [r4, #4]
	.loc 15 172 0
	ldr	r1, [r5, #8]
	ldr	r0, [r4, #8]
	bl	__aeabi_fadd
	.loc 15 175 0
	@ sp needed for prologue
	.loc 15 172 0
	str	r0, [r4, #8]
	.loc 15 175 0
	mov	r0, r4
.LVL203:
.LVL204:
	pop	{r3, r4, r5, pc}
	.cfi_endproc
.LFE84:
	.fnend
	.size	_ZN9btVector3pLERKS_, .-_ZN9btVector3pLERKS_
	.global	__aeabi_fmul
	.section	.text._ZNK9btVector33dotERKS_,"axG",%progbits,_ZNK9btVector33dotERKS_,comdat
	.align	1
	.weak	_ZNK9btVector33dotERKS_
	.code	16
	.thumb_func
	.type	_ZNK9btVector33dotERKS_, %function
_ZNK9btVector33dotERKS_:
	.fnstart
.LFB88:
	.loc 15 234 0
	.cfi_startproc
	.save	{r4, r5, r6, lr}
	push	{r4, r5, r6, lr}
.LCFI42:
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
.LVL205:
	.loc 15 234 0
	mov	r5, r1
	mov	r4, r0
	.loc 15 251 0
	ldr	r1, [r1]
.LVL206:
	ldr	r0, [r0]
.LVL207:
	bl	__aeabi_fmul
	ldr	r1, [r5, #4]
	add	r6, r0, #0
	ldr	r0, [r4, #4]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r6, #0
	bl	__aeabi_fadd
	ldr	r1, [r5, #8]
	add	r6, r0, #0
	ldr	r0, [r4, #8]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r6, #0
	bl	__aeabi_fadd
	.loc 15 253 0
	@ sp needed for prologue
.LVL208:
.LVL209:
	pop	{r4, r5, r6, pc}
	.cfi_endproc
.LFE88:
	.fnend
	.size	_ZNK9btVector33dotERKS_, .-_ZNK9btVector33dotERKS_
	.global	__aeabi_fdiv
	.section	.text._ZN9btVector39normalizeEv,"axG",%progbits,_ZN9btVector39normalizeEv,comdat
	.align	1
	.weak	_ZN9btVector39normalizeEv
	.code	16
	.thumb_func
	.type	_ZN9btVector39normalizeEv, %function
_ZN9btVector39normalizeEv:
	.fnstart
.LFB92:
	.loc 15 290 0
	.cfi_startproc
	.save	{r3, r4, r5, lr}
	push	{r3, r4, r5, lr}
.LCFI43:
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	.cfi_offset 4, -12
	.cfi_offset 5, -8
	.cfi_offset 14, -4
.LVL210:
	.loc 15 290 0
	mov	r4, r0
.LBB6368:
.LBB6369:
.LBB6370:
	.loc 15 258 0
	mov	r1, r4
	bl	_ZNK9btVector33dotERKS_
.LVL211:
.LBE6370:
.LBE6369:
.LBB6371:
.LBB6372:
	.file 16 "jni/../../../bullet4droid/jni/src/LinearMath/btScalar.h"
	.loc 16 382 0
	bl	sqrtf
.LVL212:
	add	r1, r0, #0
.LVL213:
.LBE6372:
.LBE6371:
.LBE6368:
.LBB6373:
.LBB6374:
	.loc 15 228 0
	mov	r0, #254
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
	add	r5, r0, #0
.LVL214:
.LBB6375:
.LBB6376:
	.loc 15 205 0
	add	r1, r5, #0
	ldr	r0, [r4]
	bl	__aeabi_fmul
	.loc 15 206 0
	add	r1, r5, #0
	.loc 15 205 0
	str	r0, [r4]
	.loc 15 206 0
	ldr	r0, [r4, #4]
	bl	__aeabi_fmul
	.loc 15 207 0
	add	r1, r5, #0
	.loc 15 206 0
	str	r0, [r4, #4]
	.loc 15 207 0
	ldr	r0, [r4, #8]
	bl	__aeabi_fmul
.LBE6376:
.LBE6375:
.LBE6374:
.LBE6373:
	.loc 15 330 0
	@ sp needed for prologue
.LBB6380:
.LBB6379:
.LBB6378:
.LBB6377:
	.loc 15 207 0
	str	r0, [r4, #8]
.LBE6377:
.LBE6378:
.LBE6379:
.LBE6380:
	.loc 15 330 0
	mov	r0, r4
.LVL215:
	pop	{r3, r4, r5, pc}
	.cfi_endproc
.LFE92:
	.fnend
	.size	_ZN9btVector39normalizeEv, .-_ZN9btVector39normalizeEv
	.global	__aeabi_fsub
	.section	.text._ZNK9btVector35crossERKS_,"axG",%progbits,_ZNK9btVector35crossERKS_,comdat
	.align	1
	.weak	_ZNK9btVector35crossERKS_
	.code	16
	.thumb_func
	.type	_ZNK9btVector35crossERKS_, %function
_ZNK9btVector35crossERKS_:
	.fnstart
.LFB95:
	.loc 15 367 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI44:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL216:
	.loc 15 400 0
	ldr	r3, [r1, #4]
	.loc 15 367 0
	.pad #20
	sub	sp, sp, #20
.LCFI45:
	.cfi_def_cfa_offset 40
	.loc 15 400 0
	ldr	r6, [r2, #8]
	str	r3, [sp]
	ldr	r3, [r2, #4]
	.loc 15 401 0
	ldr	r2, [r2]
.LVL217:
	.loc 15 367 0
	mov	r4, r0
	.loc 15 400 0
	ldr	r5, [r1, #8]
	.loc 15 401 0
	ldr	r7, [r1]
.LVL218:
	.loc 15 402 0
	ldr	r0, [sp]
.LVL219:
	add	r1, r6, #0
.LVL220:
	.loc 15 400 0
	str	r3, [sp, #4]
	.loc 15 401 0
	str	r2, [sp, #8]
	.loc 15 402 0
	bl	__aeabi_fmul
	ldr	r1, [sp, #4]
	str	r0, [sp, #12]
	add	r0, r5, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	ldr	r0, [sp, #12]
	bl	__aeabi_fsub
	ldr	r1, [sp, #8]
.LBB6381:
.LBB6382:
.LBB6383:
	.loc 15 132 0
	str	r0, [r4]
.LBE6383:
.LBE6382:
.LBE6381:
	.loc 15 402 0
	add	r0, r5, #0
	bl	__aeabi_fmul
	add	r1, r6, #0
	add	r5, r0, #0
	add	r0, r7, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fsub
	ldr	r1, [sp, #4]
.LBB6390:
.LBB6387:
.LBB6384:
	.loc 15 133 0
	str	r0, [r4, #4]
.LBE6384:
.LBE6387:
.LBE6390:
	.loc 15 402 0
	add	r0, r7, #0
	bl	__aeabi_fmul
	ldr	r1, [sp, #8]
	add	r5, r0, #0
	ldr	r0, [sp]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fsub
.LBB6391:
.LBB6388:
.LBB6385:
	.loc 15 135 0
	mov	r3, #0
.LBE6385:
.LBE6388:
.LBE6391:
	.loc 15 404 0
	add	sp, sp, #20
.LBB6392:
.LBB6389:
.LBB6386:
	.loc 15 134 0
	str	r0, [r4, #8]
	.loc 15 135 0
	str	r3, [r4, #12]
.LBE6386:
.LBE6389:
.LBE6392:
	.loc 15 404 0
	mov	r0, r4
	@ sp needed for prologue
.LVL221:
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE95:
	.fnend
	.size	_ZNK9btVector35crossERKS_, .-_ZNK9btVector35crossERKS_
	.global	__aeabi_fcmplt
	.section	.text._ZN9btVector36setMaxERKS_,"axG",%progbits,_ZN9btVector36setMaxERKS_,comdat
	.align	1
	.weak	_ZN9btVector36setMaxERKS_
	.code	16
	.thumb_func
	.type	_ZN9btVector36setMaxERKS_, %function
_ZN9btVector36setMaxERKS_:
	.fnstart
.LFB119:
	.loc 15 599 0
	.cfi_startproc
	.save	{r4, r5, r6, lr}
	push	{r4, r5, r6, lr}
.LCFI46:
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
.LVL222:
	.loc 8 1535 0
	ldr	r6, [r1]
.LVL223:
	.loc 15 599 0
	mov	r4, r0
	mov	r5, r1
.LBB6393:
.LBB6394:
	.file 17 "jni/../../../bullet4droid/jni/src/LinearMath/btMinMax.h"
	.loc 17 52 0
	ldr	r0, [r0]
.LVL224:
	add	r1, r6, #0
.LVL225:
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L267
	.loc 17 54 0
	str	r6, [r4]
.L267:
	.loc 8 1535 0
	ldr	r6, [r5, #4]
.LVL226:
.LBE6394:
.LBE6393:
.LBB6395:
.LBB6396:
	.loc 17 52 0
	ldr	r0, [r4, #4]
	add	r1, r6, #0
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L269
	.loc 17 54 0
	str	r6, [r4, #4]
.L269:
	.loc 8 1535 0
	ldr	r6, [r5, #8]
.LVL227:
.LBE6396:
.LBE6395:
.LBB6397:
.LBB6398:
	.loc 17 52 0
	ldr	r0, [r4, #8]
	add	r1, r6, #0
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L271
	.loc 17 54 0
	str	r6, [r4, #8]
.L271:
.LVL228:
	.loc 8 1535 0
	ldr	r5, [r5, #12]
.LVL229:
.LBE6398:
.LBE6397:
.LBB6399:
.LBB6400:
	.loc 17 52 0
	ldr	r0, [r4, #12]
	add	r1, r5, #0
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L266
	.loc 17 54 0
	str	r5, [r4, #12]
.L266:
.LBE6400:
.LBE6399:
	.loc 15 611 0
	@ sp needed for prologue
.LVL230:
	pop	{r4, r5, r6, pc}
	.cfi_endproc
.LFE119:
	.fnend
	.size	_ZN9btVector36setMaxERKS_, .-_ZN9btVector36setMaxERKS_
	.section	.text._ZN9btVector36setMinERKS_,"axG",%progbits,_ZN9btVector36setMinERKS_,comdat
	.align	1
	.weak	_ZN9btVector36setMinERKS_
	.code	16
	.thumb_func
	.type	_ZN9btVector36setMinERKS_, %function
_ZN9btVector36setMinERKS_:
	.fnstart
.LFB120:
	.loc 15 616 0
	.cfi_startproc
	.save	{r4, r5, r6, lr}
	push	{r4, r5, r6, lr}
.LCFI47:
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
.LVL231:
	.loc 8 1535 0
	ldr	r6, [r1]
	.loc 15 616 0
	mov	r4, r0
.LVL232:
	mov	r5, r1
.LBB6401:
.LBB6402:
	.loc 17 43 0
	add	r0, r6, #0
.LVL233:
	ldr	r1, [r4]
.LVL234:
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L280
	.loc 17 45 0
	str	r6, [r4]
.L280:
	.loc 8 1535 0
	ldr	r6, [r5, #4]
.LVL235:
.LBE6402:
.LBE6401:
.LBB6403:
.LBB6404:
	.loc 17 43 0
	ldr	r1, [r4, #4]
	add	r0, r6, #0
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L282
	.loc 17 45 0
	str	r6, [r4, #4]
.L282:
	.loc 8 1535 0
	ldr	r6, [r5, #8]
.LVL236:
.LBE6404:
.LBE6403:
.LBB6405:
.LBB6406:
	.loc 17 43 0
	ldr	r1, [r4, #8]
	add	r0, r6, #0
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L284
	.loc 17 45 0
	str	r6, [r4, #8]
.L284:
.LVL237:
	.loc 8 1535 0
	ldr	r5, [r5, #12]
.LVL238:
.LBE6406:
.LBE6405:
.LBB6407:
.LBB6408:
	.loc 17 43 0
	ldr	r1, [r4, #12]
	add	r0, r5, #0
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L279
	.loc 17 45 0
	str	r5, [r4, #12]
.L279:
.LBE6408:
.LBE6407:
	.loc 15 628 0
	@ sp needed for prologue
.LVL239:
	pop	{r4, r5, r6, pc}
	.cfi_endproc
.LFE120:
	.fnend
	.size	_ZN9btVector36setMinERKS_, .-_ZN9btVector36setMinERKS_
	.section	.text._ZN16btCollisionWorld14debugDrawWorldEv,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorld14debugDrawWorldEv
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld14debugDrawWorldEv, %function
_ZN16btCollisionWorld14debugDrawWorldEv:
	.fnstart
.LFB1647:
	.loc 8 1415 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI48:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL240:
.LBB6409:
	.loc 8 1416 0
	ldr	r3, [r0]
.LBE6409:
	.loc 8 1415 0
	.pad #124
	sub	sp, sp, #124
.LCFI49:
	.cfi_def_cfa_offset 144
	.loc 8 1415 0
	mov	r5, r0
.LBB6436:
	.loc 8 1416 0
	ldr	r3, [r3, #20]
	blx	r3
.LVL241:
	cmp	r0, #0
	beq	.L319
	.loc 8 1416 0 is_stmt 0 discriminator 1
	ldr	r3, [r5]
	mov	r0, r5
	ldr	r3, [r3, #20]
	blx	r3
	ldr	r3, [r0]
	ldr	r3, [r3, #48]
	blx	r3
	lsl	r1, r0, #28
	bpl	.L319
.LVL242:
.LBB6410:
.LBB6411:
.LBB6412:
	.loc 4 133 0 is_stmt 1
	ldr	r0, [r5, #24]
.LBE6412:
.LBE6411:
.LBB6413:
.LBB6414:
.LBB6415:
	.loc 8 1420 0
	mov	r7, #0
.LBE6415:
.LBE6414:
.LBE6413:
	.loc 8 1418 0
	ldr	r3, [r0]
	ldr	r3, [r3, #36]
	blx	r3
.LBB6420:
.LBB6418:
.LBB6416:
	.loc 15 132 0
	mov	r3, #254
	lsl	r3, r3, #22
	str	r3, [sp, #104]
	.loc 15 133 0
	str	r3, [sp, #108]
	.loc 15 134 0
	mov	r3, #0
.LBE6416:
.LBE6418:
.LBE6420:
	.loc 8 1418 0
	str	r0, [sp, #12]
.LVL243:
.LBB6421:
.LBB6419:
.LBB6417:
	.loc 15 134 0
	str	r3, [sp, #112]
	.loc 15 135 0
	str	r3, [sp, #116]
	b	.L294
.LVL244:
.L297:
.LBE6417:
.LBE6419:
.LBE6421:
.LBB6422:
.LBB6423:
.LBB6424:
.LBB6425:
	.loc 4 133 0
	ldr	r0, [r5, #24]
.LBE6425:
.LBE6424:
	.loc 8 1422 0
	mov	r1, r7
.LBB6426:
	.loc 8 1427 0
	mov	r6, #0
.LBE6426:
	.loc 8 1422 0
	ldr	r3, [r0]
	ldr	r3, [r3, #40]
	blx	r3
.LBB6431:
.LBB6432:
	.file 18 "jni/../../../bullet4droid/jni/src/BulletCollision/NarrowPhaseCollision/btPersistentManifold.h"
	.loc 18 109 0
	mov	r2, #187
	lsl	r2, r2, #2
	ldr	r2, [r0, r2]
.LBE6432:
.LBE6431:
	.loc 8 1422 0
	str	r0, [sp, #8]
.LVL245:
.LBB6434:
.LBB6433:
	.loc 18 109 0
	str	r2, [sp, #20]
.LVL246:
.LBE6433:
.LBE6434:
.LBB6435:
	.loc 8 1427 0
	b	.L295
.LVL247:
.L296:
	.loc 8 1429 0
	mov	r3, #184
	mov	r4, r3
	mul	r4, r6
	ldr	r1, [sp, #8]
.LBB6427:
	.loc 8 1430 0
	ldr	r3, [r5]
	mov	r0, r5
.LBE6427:
	.loc 8 1429 0
	add	r4, r1, r4
	add	r2, r4, #4
	str	r2, [sp, #16]
.LBB6430:
	.loc 8 1430 0
	ldr	r3, [r3, #20]
	blx	r3
.LVL248:
	ldr	r3, [r0]
	mov	r1, r4
	mov	r2, r4
	mov	ip, r3
	ldr	r3, [sp, #16]
.LBB6428:
.LBB6429:
	.file 19 "jni/../../../bullet4droid/jni/src/BulletCollision/NarrowPhaseCollision/btManifoldPoint.h"
	.loc 19 128 0
	add	r4, r4, #152
.LBE6429:
.LBE6428:
	.loc 8 1430 0
	ldr	r4, [r4]
	ldr	r3, [r3, #80]
	add	r1, r1, #36
	str	r4, [sp]
	str	r3, [sp, #16]
	add	r3, sp, #104
	str	r3, [sp, #4]
	mov	r3, ip
	ldr	r4, [r3, #32]
	add	r2, r2, #68
	ldr	r3, [sp, #16]
	blx	r4
.LBE6430:
	.loc 8 1427 0 discriminator 2
	add	r6, r6, #1
.LVL249:
.L295:
	.loc 8 1427 0 is_stmt 0 discriminator 1
	ldr	r1, [sp, #20]
	cmp	r6, r1
	blt	.L296
.LBE6435:
.LBE6423:
	.loc 8 1420 0 is_stmt 1
	add	r7, r7, #1
.LVL250:
.L294:
	.loc 8 1420 0 is_stmt 0 discriminator 1
	ldr	r2, [sp, #12]
	cmp	r7, r2
	blt	.L297
.LVL251:
.L319:
.LBE6422:
.LBE6410:
.LBE6436:
.LBB6437:
	.loc 8 1435 0 is_stmt 1
	ldr	r3, [r5]
	mov	r0, r5
	ldr	r3, [r3, #20]
	blx	r3
	cmp	r0, #0
	bne	.LCB3445
	b	.L292	@long jump
.LCB3445:
	.loc 8 1435 0 is_stmt 0 discriminator 1
	ldr	r3, [r5]
	mov	r0, r5
.LBB6438:
.LBB6439:
.LBB6440:
.LBB6441:
.LBB6442:
.LBB6443:
.LBB6444:
.LBB6445:
.LBB6446:
	.loc 15 133 0 is_stmt 1
	mov	r7, #0
.LBE6446:
.LBE6445:
.LBE6444:
.LBE6443:
.LBE6442:
.LBE6441:
.LBE6440:
.LBE6439:
.LBE6438:
	.loc 8 1435 0 discriminator 1
	ldr	r3, [r3, #20]
	blx	r3
	ldr	r3, [r0]
	ldr	r3, [r3, #48]
	blx	r3
	mov	r3, #0
	str	r3, [sp, #8]
	lsl	r1, r0, #30
	beq	.LCB3478
	b	.L322	@long jump
.LCB3478:
	b	.L292
.LVL252:
.L318:
.LBB6504:
.LBB6503:
.LBB6502:
	.loc 8 1441 0
	ldr	r1, [sp, #8]
.LVL253:
	ldr	r3, [r5, #16]
	lsl	r2, r1, #2
	ldr	r6, [r2, r3]
.LVL254:
.LBB6501:
.LBB6484:
.LBB6485:
	.loc 9 391 0
	mov	r3, r6
	add	r3, r3, #204
.LBE6485:
.LBE6484:
	.loc 8 1442 0
	ldr	r3, [r3]
	lsl	r2, r3, #26
	bpl	.LCB3508
	b	.L300	@long jump
.LCB3508:
.LVL255:
.LBB6486:
	.loc 8 1444 0
	ldr	r3, [r5]
	mov	r0, r5
	ldr	r3, [r3, #20]
	blx	r3
	cmp	r0, #0
	beq	.L320
	.loc 8 1444 0 is_stmt 0 discriminator 1
	ldr	r3, [r5]
	mov	r0, r5
	ldr	r3, [r3, #20]
	blx	r3
	ldr	r3, [r0]
	ldr	r3, [r3, #48]
	blx	r3
	lsl	r3, r0, #31
	bpl	.L320
.LVL256:
.LBB6487:
.LBB6488:
.LBB6489:
.LBB6490:
	.loc 15 132 0 is_stmt 1
	mov	r3, #254
	lsl	r3, r3, #22
	str	r3, [sp, #104]
	.loc 15 133 0
	str	r3, [sp, #108]
	.loc 15 134 0
	str	r3, [sp, #112]
.LBE6490:
.LBE6489:
.LBE6488:
.LBB6493:
.LBB6494:
	.loc 9 236 0
	mov	r3, r6
.LBE6494:
.LBE6493:
.LBB6496:
.LBB6492:
.LBB6491:
	.loc 15 135 0
	str	r7, [sp, #116]
.LVL257:
.LBE6491:
.LBE6492:
.LBE6496:
.LBB6497:
.LBB6495:
	.loc 9 236 0
	add	r3, r3, #216
.LBE6495:
.LBE6497:
	.loc 8 1447 0
	ldr	r0, [r3]
	sub	r0, r0, #1
	cmp	r0, #4
	bhi	.L303
	bl	__gnu_thumb1_case_uqi
.L309:
	.byte	(.L304-.L309)/2
	.byte	(.L305-.L309)/2
	.byte	(.L306-.L309)/2
	.byte	(.L307-.L309)/2
	.byte	(.L308-.L309)/2
	.align	1
.L305:
.LVL258:
	.loc 8 1452 0
	mov	r1, #0
	str	r1, [sp, #104]
	b	.L323
.LVL259:
.L306:
	.loc 8 1454 0
	mov	r2, #0
	str	r2, [sp, #104]
	b	.L304
.LVL260:
.L307:
	.loc 8 1456 0
	mov	r3, #0
	str	r3, [sp, #108]
	str	r3, [sp, #112]
	b	.L304
.LVL261:
.L308:
	.loc 8 1458 0
	mov	r1, #0
.LVL262:
.L323:
	str	r1, [sp, #112]
	b	.L304
.L303:
.LVL263:
	.loc 8 1461 0
	str	r7, [sp, #108]
	str	r7, [sp, #112]
.LVL264:
.L304:
	.loc 8 1465 0
	ldr	r3, [r5]
.LBB6498:
.LBB6499:
	.loc 9 216 0
	mov	r2, r6
	add	r2, r2, #192
.LBE6499:
.LBE6498:
	.loc 8 1465 0
	ldr	r4, [r3, #28]
	add	r1, r6, #4
	ldr	r2, [r2]
	mov	r0, r5
	add	r3, sp, #104
.LVL265:
	blx	r4
.LVL266:
.L320:
.LBE6487:
.LBE6486:
.LBB6500:
	.loc 8 1467 0
	ldr	r0, [r5, #72]
	cmp	r0, #0
	beq	.L300
	.loc 8 1467 0 is_stmt 0 discriminator 1
	ldr	r3, [r0]
	ldr	r3, [r3, #48]
	blx	r3
	lsl	r2, r0, #30
	bpl	.L300
.LVL267:
.LBB6483:
.LBB6451:
.LBB6449:
.LBB6447:
	.loc 15 132 0 is_stmt 1
	mov	r3, #254
	lsl	r3, r3, #22
	str	r3, [sp, #56]
.LBE6447:
.LBE6449:
.LBE6451:
.LBB6452:
.LBB6453:
	.loc 9 216 0
	mov	r3, r6
	add	r3, r3, #192
	ldr	r0, [r3]
.LBE6453:
.LBE6452:
.LBB6455:
.LBB6450:
.LBB6448:
	.loc 15 133 0
	str	r7, [sp, #60]
	.loc 15 134 0
	str	r7, [sp, #64]
	.loc 15 135 0
	str	r7, [sp, #68]
.LVL268:
.LBE6448:
.LBE6450:
.LBE6455:
.LBB6456:
.LBB6454:
	.loc 9 216 0
	str	r3, [sp, #12]
.LBE6454:
.LBE6456:
	.loc 8 1471 0
	ldr	r3, [r0]
	add	r2, sp, #24
	add	r1, r6, #4
	ldr	r4, [r3, #8]
	add	r3, sp, #40
	blx	r4
	ldr	r3, .L324
.LBB6457:
.LBB6458:
	.loc 15 187 0
	ldr	r0, [sp, #24]
.LBE6458:
.LBE6457:
.LBB6462:
.LBB6463:
.LBB6464:
	.loc 15 135 0
	str	r7, [sp, #84]
.LBE6464:
.LBE6463:
.LBE6462:
	.loc 8 1471 0
.LPIC104:
	add	r3, pc
	.loc 8 1535 0
	ldr	r3, [r3]
	ldr	r4, [r3]
.LVL269:
.LBB6467:
.LBB6459:
	.loc 15 187 0
	add	r1, r4, #0
.LBE6459:
.LBE6467:
.LBB6468:
.LBB6466:
.LBB6465:
	.loc 15 132 0
	str	r4, [sp, #72]
	.loc 15 133 0
	str	r4, [sp, #76]
	.loc 15 134 0
	str	r4, [sp, #80]
.LBE6465:
.LBE6466:
.LBE6468:
.LBB6469:
.LBB6460:
	.loc 15 187 0
	bl	__aeabi_fsub
	.loc 15 188 0
	add	r1, r4, #0
	.loc 15 187 0
	str	r0, [sp, #24]
	.loc 15 188 0
	ldr	r0, [sp, #28]
	bl	__aeabi_fsub
	.loc 15 189 0
	add	r1, r4, #0
	.loc 15 188 0
	str	r0, [sp, #28]
	.loc 15 189 0
	ldr	r0, [sp, #32]
	bl	__aeabi_fsub
.LBE6460:
.LBE6469:
	.loc 8 1474 0
	add	r1, sp, #72
.LBB6470:
.LBB6461:
	.loc 15 189 0
	str	r0, [sp, #32]
.LBE6461:
.LBE6470:
	.loc 8 1474 0
	add	r0, sp, #40
	bl	_ZN9btVector3pLERKS_
.LVL270:
	.loc 8 1478 0
	mov	r3, r5
	add	r3, r3, #44
	ldrb	r3, [r3]
	cmp	r3, #0
	beq	.L317
.LVL271:
.LBB6471:
.LBB6472:
	.loc 9 288 0
	mov	r3, r6
	add	r3, r3, #236
.LBE6472:
.LBE6471:
	.loc 8 1478 0 discriminator 1
	ldr	r3, [r3]
	cmp	r3, #2
	bne	.L317
.LVL272:
.LBB6473:
.LBB6474:
	.loc 9 191 0
	mov	r3, r6
	add	r3, r3, #204
	ldr	r3, [r3]
.LBE6474:
.LBE6473:
	.loc 8 1478 0 discriminator 3
	lsl	r1, r3, #30
	bne	.L317
.LVL273:
.LBB6475:
.LBB6476:
	.loc 9 216 0
	ldr	r2, [sp, #12]
.LBE6476:
.LBE6475:
	.loc 8 1480 0
	mov	r1, r6
	add	r1, r1, #68
.LBB6478:
.LBB6477:
	.loc 9 216 0
	ldr	r0, [r2]
.LVL274:
.LBE6477:
.LBE6478:
	.loc 8 1480 0
	add	r2, sp, #88
	ldr	r3, [r0]
	ldr	r4, [r3, #8]
	add	r3, sp, #104
.LVL275:
	blx	r4
.LVL276:
.LBB6479:
.LBB6480:
	.loc 15 187 0
	ldr	r0, [sp, #88]
	ldr	r1, [sp, #72]
	bl	__aeabi_fsub
	.loc 15 188 0
	ldr	r1, [sp, #76]
	.loc 15 187 0
	str	r0, [sp, #88]
	.loc 15 188 0
	ldr	r0, [sp, #92]
	bl	__aeabi_fsub
	.loc 15 189 0
	ldr	r1, [sp, #80]
	.loc 15 188 0
	str	r0, [sp, #92]
	.loc 15 189 0
	ldr	r0, [sp, #96]
	bl	__aeabi_fsub
.LBE6480:
.LBE6479:
	.loc 8 1482 0
	add	r1, sp, #72
.LBB6482:
.LBB6481:
	.loc 15 189 0
	str	r0, [sp, #96]
.LBE6481:
.LBE6482:
	.loc 8 1482 0
	add	r0, sp, #104
.LVL277:
	bl	_ZN9btVector3pLERKS_
.LVL278:
	.loc 8 1483 0
	add	r0, sp, #24
	add	r1, sp, #88
	bl	_ZN9btVector36setMinERKS_
	.loc 8 1484 0
	add	r0, sp, #40
	add	r1, sp, #104
.LVL279:
	bl	_ZN9btVector36setMaxERKS_
.LVL280:
.L317:
	.loc 8 1487 0
	ldr	r0, [r5, #72]
	add	r1, sp, #24
	add	r2, sp, #40
	ldr	r3, [r0]
	ldr	r4, [r3, #52]
	add	r3, sp, #56
	blx	r4
.LVL281:
.L300:
.LBE6483:
.LBE6500:
.LBE6501:
.LBE6502:
	.loc 8 1439 0
	ldr	r3, [sp, #8]
	add	r3, r3, #1
	str	r3, [sp, #8]
.LVL282:
.L322:
	.loc 8 1439 0 is_stmt 0 discriminator 1
	ldr	r3, [r5, #8]
	ldr	r1, [sp, #8]
	cmp	r1, r3
	bge	.LCB3920
	b	.L318	@long jump
.LCB3920:
.LVL283:
.L292:
.LBE6503:
.LBE6504:
.LBE6437:
	.loc 8 1493 0 is_stmt 1
	add	sp, sp, #124
	@ sp needed for prologue
.LVL284:
	pop	{r4, r5, r6, r7, pc}
.L325:
	.align	2
.L324:
	.word	gContactBreakingThreshold(GOT_PREL)+(.-(.LPIC104+4))
	.cfi_endproc
.LFE1647:
	.fnend
	.size	_ZN16btCollisionWorld14debugDrawWorldEv, .-_ZN16btCollisionWorld14debugDrawWorldEv
	.section	.text._ZplRK9btVector3S1_,"axG",%progbits,_ZplRK9btVector3S1_,comdat
	.align	1
	.weak	_ZplRK9btVector3S1_
	.code	16
	.thumb_func
	.type	_ZplRK9btVector3S1_, %function
_ZplRK9btVector3S1_:
	.fnstart
.LFB127:
	.loc 15 743 0
	.cfi_startproc
	.save	{r0, r1, r2, r4, r5, r6, r7, lr}
	push	{r0, r1, r2, r4, r5, r6, r7, lr}
.LCFI50:
	.cfi_def_cfa_offset 32
	.cfi_offset 0, -32
	.cfi_offset 1, -28
	.cfi_offset 2, -24
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL285:
	.loc 15 743 0
	mov	r6, r0
	mov	r4, r1
	.loc 15 752 0
	ldr	r0, [r1, #4]
.LVL286:
	ldr	r1, [r2, #4]
.LVL287:
	.loc 15 743 0
	mov	r5, r2
	.loc 15 752 0
	bl	__aeabi_fadd
.LVL288:
	ldr	r1, [r5, #8]
	add	r7, r0, #0
	ldr	r0, [r4, #8]
	bl	__aeabi_fadd
	ldr	r1, [r5]
	str	r0, [sp, #4]
.LVL289:
	ldr	r0, [r4]
	bl	__aeabi_fadd
.LBB6505:
.LBB6506:
.LBB6507:
	.loc 15 134 0
	ldr	r3, [sp, #4]
	.loc 15 132 0
	str	r0, [r6]
	.loc 15 133 0
	str	r7, [r6, #4]
	.loc 15 134 0
	str	r3, [r6, #8]
	.loc 15 135 0
	mov	r3, #0
.LBE6507:
.LBE6506:
.LBE6505:
	.loc 15 754 0
	mov	r0, r6
.LBB6510:
.LBB6509:
.LBB6508:
	.loc 15 135 0
	str	r3, [r6, #12]
.LBE6508:
.LBE6509:
.LBE6510:
	.loc 15 754 0
	@ sp needed for prologue
.LVL290:
.LVL291:
.LVL292:
	pop	{r1, r2, r3, r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE127:
	.fnend
	.size	_ZplRK9btVector3S1_, .-_ZplRK9btVector3S1_
	.section	.text._ZmiRK9btVector3S1_,"axG",%progbits,_ZmiRK9btVector3S1_,comdat
	.align	1
	.weak	_ZmiRK9btVector3S1_
	.code	16
	.thumb_func
	.type	_ZmiRK9btVector3S1_, %function
_ZmiRK9btVector3S1_:
	.fnstart
.LFB129:
	.loc 15 775 0
	.cfi_startproc
	.save	{r0, r1, r2, r4, r5, r6, r7, lr}
	push	{r0, r1, r2, r4, r5, r6, r7, lr}
.LCFI51:
	.cfi_def_cfa_offset 32
	.cfi_offset 0, -32
	.cfi_offset 1, -28
	.cfi_offset 2, -24
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL293:
	.loc 15 775 0
	mov	r6, r0
	mov	r4, r1
	.loc 15 788 0
	ldr	r0, [r1, #4]
.LVL294:
	ldr	r1, [r2, #4]
.LVL295:
	.loc 15 775 0
	mov	r5, r2
	.loc 15 788 0
	bl	__aeabi_fsub
.LVL296:
	ldr	r1, [r5, #8]
	add	r7, r0, #0
	ldr	r0, [r4, #8]
	bl	__aeabi_fsub
	ldr	r1, [r5]
	str	r0, [sp, #4]
.LVL297:
	ldr	r0, [r4]
	bl	__aeabi_fsub
.LBB6511:
.LBB6512:
.LBB6513:
	.loc 15 134 0
	ldr	r3, [sp, #4]
	.loc 15 132 0
	str	r0, [r6]
	.loc 15 133 0
	str	r7, [r6, #4]
	.loc 15 134 0
	str	r3, [r6, #8]
	.loc 15 135 0
	mov	r3, #0
.LBE6513:
.LBE6512:
.LBE6511:
	.loc 15 790 0
	mov	r0, r6
.LBB6516:
.LBB6515:
.LBB6514:
	.loc 15 135 0
	str	r3, [r6, #12]
.LBE6514:
.LBE6515:
.LBE6516:
	.loc 15 790 0
	@ sp needed for prologue
.LVL298:
.LVL299:
.LVL300:
	pop	{r1, r2, r3, r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE129:
	.fnend
	.size	_ZmiRK9btVector3S1_, .-_ZmiRK9btVector3S1_
	.section	.text._ZN12btQuaternion9normalizeEv,"axG",%progbits,_ZN12btQuaternion9normalizeEv,comdat
	.align	1
	.weak	_ZN12btQuaternion9normalizeEv
	.code	16
	.thumb_func
	.type	_ZN12btQuaternion9normalizeEv, %function
_ZN12btQuaternion9normalizeEv:
	.fnstart
.LFB220:
	.file 20 "jni/../../../bullet4droid/jni/src/LinearMath/btQuaternion.h"
	.loc 20 332 0
	.cfi_startproc
	.save	{r0, r1, r2, r4, r5, r6, r7, lr}
	push	{r0, r1, r2, r4, r5, r6, r7, lr}
.LCFI52:
	.cfi_def_cfa_offset 32
	.cfi_offset 0, -32
	.cfi_offset 1, -28
	.cfi_offset 2, -24
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL301:
.LBB6517:
.LBB6518:
.LBB6519:
.LBB6520:
	.loc 20 311 0
	ldr	r1, [r0]
.LVL302:
.LBE6520:
.LBE6519:
.LBE6518:
.LBE6517:
	.loc 20 332 0
	mov	r4, r0
.LBB6526:
.LBB6523:
.LBB6522:
.LBB6521:
	.loc 20 313 0
	ldr	r6, [r0, #8]
	.loc 20 314 0
	ldr	r7, [r0, #12]
	.loc 20 312 0
	ldr	r5, [r0, #4]
.LVL303:
	.loc 20 314 0
	add	r0, r1, #0
.LVL304:
	bl	__aeabi_fmul
.LVL305:
	add	r1, r5, #0
	str	r0, [sp, #4]
	add	r0, r5, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	ldr	r0, [sp, #4]
	bl	__aeabi_fadd
	add	r1, r6, #0
	add	r5, r0, #0
	add	r0, r6, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	add	r1, r7, #0
	add	r5, r0, #0
	add	r0, r7, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
.LBE6521:
.LBE6522:
.LBE6523:
.LBB6524:
.LBB6525:
	.loc 16 382 0
	bl	sqrtf
	add	r1, r0, #0
.LVL306:
.LBE6525:
.LBE6524:
.LBE6526:
.LBB6527:
.LBB6528:
	.loc 20 385 0
	mov	r0, #254
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
	add	r5, r0, #0
.LVL307:
.LBB6529:
.LBB6530:
	.loc 20 198 0
	add	r1, r5, #0
	ldr	r0, [r4]
	bl	__aeabi_fmul
	.loc 20 199 0
	add	r1, r5, #0
	.loc 20 198 0
	str	r0, [r4]
	.loc 20 199 0
	ldr	r0, [r4, #4]
	bl	__aeabi_fmul
	.loc 20 200 0
	add	r1, r5, #0
	.loc 20 199 0
	str	r0, [r4, #4]
	.loc 20 200 0
	ldr	r0, [r4, #8]
	bl	__aeabi_fmul
	.loc 20 201 0
	add	r1, r5, #0
	.loc 20 200 0
	str	r0, [r4, #8]
	.loc 20 201 0
	ldr	r0, [r4, #12]
	bl	__aeabi_fmul
.LBE6530:
.LBE6529:
.LBE6528:
.LBE6527:
	.loc 20 353 0
	@ sp needed for prologue
.LBB6534:
.LBB6533:
.LBB6532:
.LBB6531:
	.loc 20 201 0
	str	r0, [r4, #12]
.LBE6531:
.LBE6532:
.LBE6533:
.LBE6534:
	.loc 20 353 0
	mov	r0, r4
.LVL308:
	pop	{r1, r2, r3, r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE220:
	.fnend
	.size	_ZN12btQuaternion9normalizeEv, .-_ZN12btQuaternion9normalizeEv
	.section	.text._ZN11btMatrix3x3C2ERKS_,"axG",%progbits,_ZN11btMatrix3x3C5ERKS_,comdat
	.align	1
	.weak	_ZN11btMatrix3x3C2ERKS_
	.code	16
	.thumb_func
	.type	_ZN11btMatrix3x3C2ERKS_, %function
_ZN11btMatrix3x3C2ERKS_:
	.fnstart
.LFB259:
	.file 21 "jni/../../../bullet4droid/jni/src/LinearMath/btMatrix3x3.h"
	.loc 21 114 0
	.cfi_startproc
	.save	{r4, r5, r6, lr}
	push	{r4, r5, r6, lr}
.LCFI53:
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
.LVL309:
.LBB6535:
	.loc 21 116 0
	mov	r3, r0
	mov	r2, r1
	ldmia	r2!, {r4, r5, r6}
	stmia	r3!, {r4, r5, r6}
	ldr	r2, [r2]
.LBE6535:
	.loc 21 119 0
	@ sp needed for prologue
.LBB6536:
	.loc 21 116 0
	str	r2, [r3]
	.loc 21 117 0
	mov	r2, r1
	add	r3, r3, #4
	add	r2, r2, #16
	ldmia	r2!, {r4, r5, r6}
	stmia	r3!, {r4, r5, r6}
	ldr	r2, [r2]
	.loc 21 118 0
	add	r1, r1, #32
.LVL310:
	.loc 21 117 0
	str	r2, [r3]
	.loc 21 118 0
	add	r3, r3, #4
	ldmia	r1!, {r2, r4, r5}
	stmia	r3!, {r2, r4, r5}
.LVL311:
	ldr	r2, [r1]
	str	r2, [r3]
.LBE6536:
	.loc 21 119 0
	pop	{r4, r5, r6, pc}
	.cfi_endproc
.LFE259:
	.fnend
	.size	_ZN11btMatrix3x3C2ERKS_, .-_ZN11btMatrix3x3C2ERKS_
	.section	.text._ZN11btMatrix3x3aSERKS_,"axG",%progbits,_ZN11btMatrix3x3aSERKS_,comdat
	.align	1
	.weak	_ZN11btMatrix3x3aSERKS_
	.code	16
	.thumb_func
	.type	_ZN11btMatrix3x3aSERKS_, %function
_ZN11btMatrix3x3aSERKS_:
	.fnstart
.LFB261:
	.loc 21 122 0
	.cfi_startproc
	.save	{r4, r5, r6, lr}
	push	{r4, r5, r6, lr}
.LCFI54:
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
.LVL312:
	.loc 21 124 0
	mov	r3, r0
	mov	r2, r1
	ldmia	r2!, {r4, r5, r6}
	stmia	r3!, {r4, r5, r6}
	ldr	r2, [r2]
	.loc 21 128 0
	@ sp needed for prologue
	.loc 21 124 0
	str	r2, [r3]
	.loc 21 125 0
	mov	r2, r1
	add	r3, r3, #4
	add	r2, r2, #16
	ldmia	r2!, {r4, r5, r6}
	stmia	r3!, {r4, r5, r6}
	ldr	r2, [r2]
	.loc 21 126 0
	add	r1, r1, #32
.LVL313:
	.loc 21 125 0
	str	r2, [r3]
	.loc 21 126 0
	add	r3, r3, #4
	ldmia	r1!, {r2, r4, r5}
	stmia	r3!, {r2, r4, r5}
.LVL314:
	ldr	r2, [r1]
	str	r2, [r3]
	.loc 21 128 0
	pop	{r4, r5, r6, pc}
	.cfi_endproc
.LFE261:
	.fnend
	.size	_ZN11btMatrix3x3aSERKS_, .-_ZN11btMatrix3x3aSERKS_
	.section	.text._ZN11btMatrix3x311setRotationERK12btQuaternion,"axG",%progbits,_ZN11btMatrix3x311setRotationERK12btQuaternion,comdat
	.align	1
	.weak	_ZN11btMatrix3x311setRotationERK12btQuaternion
	.code	16
	.thumb_func
	.type	_ZN11btMatrix3x311setRotationERK12btQuaternion, %function
_ZN11btMatrix3x311setRotationERK12btQuaternion:
	.fnstart
.LFB268:
	.loc 21 209 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI55:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL315:
.LBB6537:
.LBB6538:
.LBB6539:
.LBB6540:
	.loc 20 311 0
	ldr	r5, [r1]
.LVL316:
	.loc 20 313 0
	ldr	r3, [r1, #8]
.LBE6540:
.LBE6539:
.LBE6538:
.LBE6537:
	.loc 21 209 0
	.pad #44
	sub	sp, sp, #44
.LCFI56:
	.cfi_def_cfa_offset 64
	.loc 21 209 0
	mov	r4, r0
.LBB6577:
.LBB6543:
.LBB6542:
.LBB6541:
	.loc 20 312 0
	ldr	r7, [r1, #4]
.LVL317:
	.loc 20 314 0
	ldr	r6, [r1, #12]
	add	r0, r5, #0
.LVL318:
	add	r1, r5, #0
.LVL319:
	.loc 20 313 0
	str	r3, [sp, #16]
	.loc 20 314 0
	bl	__aeabi_fmul
	add	r1, r7, #0
	str	r0, [sp, #4]
	add	r0, r7, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	ldr	r0, [sp, #4]
	bl	__aeabi_fadd
	str	r0, [sp, #4]
	ldr	r0, [sp, #16]
	add	r1, r0, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	ldr	r0, [sp, #4]
	bl	__aeabi_fadd
	add	r1, r6, #0
	str	r0, [sp, #4]
	add	r0, r6, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	ldr	r0, [sp, #4]
	bl	__aeabi_fadd
	add	r1, r0, #0
.LBE6541:
.LBE6542:
.LBE6543:
	.loc 21 213 0
	mov	r0, #128
	lsl	r0, r0, #23
	bl	__aeabi_fdiv
	str	r0, [sp, #4]
.LVL320:
	.loc 21 267 0
	ldr	r1, [sp, #4]
	add	r0, r5, #0
.LVL321:
	bl	__aeabi_fmul
.LVL322:
	ldr	r1, [sp, #4]
	str	r0, [sp, #12]
.LVL323:
	add	r0, r7, #0
.LVL324:
	bl	__aeabi_fmul
	ldr	r1, [sp, #4]
	str	r0, [sp, #8]
.LVL325:
	ldr	r0, [sp, #16]
.LVL326:
	bl	__aeabi_fmul
	.loc 21 268 0
	ldr	r1, [sp, #12]
	.loc 21 267 0
	str	r0, [sp, #4]
.LVL327:
	.loc 21 268 0
	add	r0, r6, #0
.LVL328:
	bl	__aeabi_fmul
	ldr	r1, [sp, #8]
	str	r0, [sp, #20]
.LVL329:
	add	r0, r6, #0
.LVL330:
	bl	__aeabi_fmul
	ldr	r1, [sp, #4]
	str	r0, [sp, #24]
.LVL331:
	add	r0, r6, #0
.LVL332:
	bl	__aeabi_fmul
	.loc 21 269 0
	ldr	r1, [sp, #12]
	.loc 21 268 0
	str	r0, [sp, #28]
.LVL333:
	.loc 21 269 0
	add	r0, r5, #0
.LVL334:
	bl	__aeabi_fmul
	ldr	r1, [sp, #8]
	str	r0, [sp, #12]
.LVL335:
	add	r0, r5, #0
.LVL336:
	bl	__aeabi_fmul
	str	r0, [sp, #32]
.LVL337:
	ldr	r1, [sp, #4]
	add	r0, r5, #0
.LVL338:
	bl	__aeabi_fmul
	.loc 21 270 0
	ldr	r1, [sp, #8]
	.loc 21 269 0
	str	r0, [sp, #36]
.LVL339:
	.loc 21 270 0
	add	r0, r7, #0
.LVL340:
	bl	__aeabi_fmul
	ldr	r1, [sp, #4]
	str	r0, [sp, #8]
.LVL341:
	add	r0, r7, #0
.LVL342:
	bl	__aeabi_fmul
	ldr	r1, [sp, #4]
	add	r7, r0, #0
.LVL343:
	ldr	r0, [sp, #16]
.LVL344:
	bl	__aeabi_fmul
	add	r6, r0, #0
.LVL345:
	.loc 21 274 0
	add	r1, r6, #0
	ldr	r0, [sp, #8]
.LVL346:
	bl	__aeabi_fadd
.LVL347:
	add	r1, r0, #0
	mov	r0, #254
	lsl	r0, r0, #22
	bl	__aeabi_fsub
	ldr	r1, [sp, #28]
.LBB6544:
.LBB6545:
.LBB6546:
	.loc 15 632 0
	str	r0, [r4]
.LBE6546:
.LBE6545:
.LBE6544:
	.loc 21 274 0
	ldr	r0, [sp, #32]
	bl	__aeabi_fsub
	ldr	r1, [sp, #24]
.LBB6567:
.LBB6550:
.LBB6547:
	.loc 15 633 0
	str	r0, [r4, #4]
.LBE6547:
.LBE6550:
.LBE6567:
	.loc 21 274 0
	ldr	r0, [sp, #36]
	bl	__aeabi_fadd
.LBB6568:
.LBB6551:
.LBB6548:
	.loc 15 635 0
	mov	r5, #0
.LBE6548:
.LBE6551:
.LBE6568:
	.loc 21 274 0
	ldr	r1, [sp, #28]
.LBB6569:
.LBB6552:
.LBB6549:
	.loc 15 634 0
	str	r0, [r4, #8]
	.loc 15 635 0
	str	r5, [r4, #12]
.LVL348:
.LBE6549:
.LBE6552:
.LBE6569:
	.loc 21 274 0
	ldr	r0, [sp, #32]
	bl	__aeabi_fadd
	add	r1, r6, #0
.LBB6570:
.LBB6553:
.LBB6554:
	.loc 15 632 0
	str	r0, [r4, #16]
.LBE6554:
.LBE6553:
.LBE6570:
	.loc 21 274 0
	ldr	r0, [sp, #12]
	bl	__aeabi_fadd
	add	r1, r0, #0
	mov	r0, #254
	lsl	r0, r0, #22
	bl	__aeabi_fsub
	ldr	r1, [sp, #20]
.LBB6571:
.LBB6557:
.LBB6555:
	.loc 15 633 0
	str	r0, [r4, #20]
.LBE6555:
.LBE6557:
.LBE6571:
	.loc 21 274 0
	add	r0, r7, #0
	bl	__aeabi_fsub
	ldr	r1, [sp, #24]
.LBB6572:
.LBB6558:
.LBB6556:
	.loc 15 634 0
	str	r0, [r4, #24]
	.loc 15 635 0
	str	r5, [r4, #28]
.LVL349:
.LBE6556:
.LBE6558:
.LBE6572:
	.loc 21 274 0
	ldr	r0, [sp, #36]
	bl	__aeabi_fsub
	ldr	r1, [sp, #20]
.LBB6573:
.LBB6559:
.LBB6560:
	.loc 15 632 0
	str	r0, [r4, #32]
.LBE6560:
.LBE6559:
.LBE6573:
	.loc 21 274 0
	add	r0, r7, #0
	bl	__aeabi_fadd
	ldr	r1, [sp, #8]
.LBB6574:
.LBB6564:
.LBB6561:
	.loc 15 633 0
	str	r0, [r4, #36]
.LBE6561:
.LBE6564:
.LBE6574:
	.loc 21 274 0
	ldr	r0, [sp, #12]
	bl	__aeabi_fadd
	add	r1, r0, #0
	mov	r0, #254
	lsl	r0, r0, #22
	bl	__aeabi_fsub
.LBE6577:
	.loc 21 276 0
	add	sp, sp, #44
.LBB6578:
.LBB6575:
.LBB6565:
.LBB6562:
	.loc 15 634 0
	str	r0, [r4, #40]
.LBE6562:
.LBE6565:
.LBE6575:
.LBE6578:
	.loc 21 276 0
	@ sp needed for prologue
.LBB6579:
.LBB6576:
.LBB6566:
.LBB6563:
	.loc 15 635 0
	str	r5, [r4, #44]
.LVL350:
.LVL351:
.LVL352:
.LBE6563:
.LBE6566:
.LBE6576:
.LBE6579:
	.loc 21 276 0
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE268:
	.fnend
	.size	_ZN11btMatrix3x311setRotationERK12btQuaternion, .-_ZN11btMatrix3x311setRotationERK12btQuaternion
	.global	__aeabi_fcmpgt
	.global	__aeabi_idivmod
	.section	.text._ZNK11btMatrix3x311getRotationER12btQuaternion,"axG",%progbits,_ZNK11btMatrix3x311getRotationER12btQuaternion,comdat
	.align	1
	.weak	_ZNK11btMatrix3x311getRotationER12btQuaternion
	.code	16
	.thumb_func
	.type	_ZNK11btMatrix3x311getRotationER12btQuaternion, %function
_ZNK11btMatrix3x311getRotationER12btQuaternion:
	.fnstart
.LFB274:
	.loc 21 400 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI57:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL353:
.LBB6580:
	.loc 21 454 0
	ldr	r5, [r0, #20]
	ldr	r6, [r0]
.LVL354:
	ldr	r7, [r0, #40]
.LBE6580:
	.loc 21 400 0
	.pad #36
	sub	sp, sp, #36
.LCFI58:
	.cfi_def_cfa_offset 56
	.loc 21 400 0
	str	r1, [sp, #4]
	mov	r4, r0
.LBB6597:
	.loc 21 454 0
	add	r1, r5, #0
.LVL355:
	add	r0, r6, #0
.LVL356:
	bl	__aeabi_fadd
	add	r1, r7, #0
	bl	__aeabi_fadd
.LBB6581:
	.loc 21 458 0
	mov	r1, #0
.LBE6581:
	.loc 21 454 0
	str	r0, [sp]
.LVL357:
.LBB6592:
	.loc 21 458 0
	bl	__aeabi_fcmpgt
.LVL358:
	cmp	r0, #0
	beq	.L350
.LVL359:
.LBB6582:
	.loc 21 460 0
	mov	r1, #254
	lsl	r1, r1, #22
	ldr	r0, [sp]
	bl	__aeabi_fadd
.LBB6583:
.LBB6584:
	.loc 16 382 0
	bl	sqrtf
.LBE6584:
.LBE6583:
	.loc 21 461 0
	mov	r1, #252
	lsl	r1, r1, #22
.LBB6586:
.LBB6585:
	.loc 16 382 0
	add	r5, r0, #0
.LBE6585:
.LBE6586:
	.loc 21 461 0
	bl	__aeabi_fmul
	str	r0, [sp, #28]
	.loc 21 462 0
	mov	r0, #252
	add	r1, r5, #0
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
	.loc 21 464 0
	ldr	r1, [r4, #24]
	.loc 21 462 0
	add	r5, r0, #0
.LVL360:
	.loc 21 464 0
	ldr	r0, [r4, #36]
.LVL361:
	bl	__aeabi_fsub
	add	r1, r5, #0
	bl	__aeabi_fmul
	.loc 21 465 0
	ldr	r1, [r4, #32]
	.loc 21 464 0
	str	r0, [sp, #16]
.LVL362:
	.loc 21 465 0
	ldr	r0, [r4, #8]
	bl	__aeabi_fsub
	add	r1, r5, #0
	bl	__aeabi_fmul
	.loc 21 466 0
	ldr	r1, [r4, #4]
	.loc 21 465 0
	str	r0, [sp, #20]
.LVL363:
	.loc 21 466 0
	ldr	r0, [r4, #16]
	bl	__aeabi_fsub
	add	r1, r5, #0
	bl	__aeabi_fmul
	str	r0, [sp, #24]
	b	.L338
.LVL364:
.L350:
.LBE6582:
.LBB6587:
	.loc 21 472 0
	add	r0, r6, #0
	add	r1, r5, #0
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L351
.LVL365:
	.loc 21 472 0 is_stmt 0 discriminator 1
	add	r0, r5, #0
	add	r1, r7, #0
	bl	__aeabi_fcmplt
	.loc 21 472 0 discriminator 4
	mov	r5, r0
	sub	r0, r5, #1
	sbc	r5, r5, r0
	add	r5, r5, #1
	b	.L341
.LVL366:
.L351:
	.loc 21 472 0 discriminator 2
	add	r0, r6, #0
	add	r1, r7, #0
	bl	__aeabi_fcmplt
	.loc 21 472 0 discriminator 7
	mov	r5, r0
	sub	r0, r5, #1
	sbc	r5, r5, r0
	lsl	r5, r5, #1
.LVL367:
.L341:
	.loc 21 473 0 is_stmt 1
	add	r0, r5, #1
	mov	r1, #3
	bl	__aeabi_idivmod
	.loc 21 474 0
	add	r0, r5, #2
	.loc 21 473 0
	mov	r6, r1
.LVL368:
	.loc 21 474 0
	mov	r1, #3
.LVL369:
	bl	__aeabi_idivmod
	.loc 21 476 0
	lsl	r3, r5, #4
	add	r3, r4, r3
	str	r3, [sp]
	lsl	r3, r6, #4
	add	r3, r4, r3
	str	r3, [sp, #8]
	lsl	r3, r1, #4
	add	r3, r4, r3
	ldr	r2, [sp]
	str	r3, [sp, #12]
	ldr	r3, [sp, #8]
	lsl	r4, r6, #2
.LVL370:
	lsl	r5, r5, #2
.LVL371:
	.loc 21 474 0
	mov	r7, r1
.LVL372:
	.loc 21 476 0
	ldr	r0, [r5, r2]
	ldr	r1, [r4, r3]
.LVL373:
	bl	__aeabi_fsub
	ldr	r2, [sp, #12]
	lsl	r6, r7, #2
.LVL374:
	ldr	r1, [r6, r2]
	bl	__aeabi_fsub
	mov	r1, #254
	lsl	r1, r1, #22
	bl	__aeabi_fadd
.LBB6588:
.LBB6589:
	.loc 16 382 0
	bl	sqrtf
.LBE6589:
.LBE6588:
	.loc 21 477 0
	mov	r1, #252
	lsl	r1, r1, #22
.LBB6591:
.LBB6590:
	.loc 16 382 0
	add	r7, r0, #0
.LVL375:
.LBE6590:
.LBE6591:
	.loc 21 477 0
	bl	__aeabi_fmul
	mov	r3, #16
	add	r3, r3, r5
	mov	r2, sp
	str	r0, [r3, r2]
	.loc 21 478 0
	mov	r0, #252
	add	r1, r7, #0
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
	.loc 21 480 0
	ldr	r3, [sp, #12]
	ldr	r2, [sp, #8]
	.loc 21 478 0
	add	r7, r0, #0
.LVL376:
	.loc 21 480 0
	ldr	r0, [r4, r3]
.LVL377:
	ldr	r1, [r6, r2]
	bl	__aeabi_fsub
	add	r1, r7, #0
	bl	__aeabi_fmul
	.loc 21 481 0
	ldr	r3, [sp, #8]
	ldr	r2, [sp]
	.loc 21 480 0
	str	r0, [sp, #28]
.LVL378:
	.loc 21 481 0
	ldr	r0, [r5, r3]
	ldr	r1, [r4, r2]
	bl	__aeabi_fadd
	add	r1, r7, #0
	bl	__aeabi_fmul
	add	r4, r4, #16
	mov	r3, sp
	.loc 21 482 0
	ldr	r2, [sp, #12]
	.loc 21 481 0
	str	r0, [r4, r3]
.LVL379:
	.loc 21 482 0
	ldr	r3, [sp]
	ldr	r0, [r5, r2]
	ldr	r1, [r6, r3]
	bl	__aeabi_fadd
	add	r1, r7, #0
	bl	__aeabi_fmul
	add	r6, r6, #16
	mov	r2, sp
	str	r0, [r6, r2]
.LVL380:
.L338:
.LBE6587:
.LBE6592:
.LBB6593:
.LBB6594:
	.file 22 "jni/../../../bullet4droid/jni/src/LinearMath/btQuadWord.h"
	.loc 22 175 0
	ldr	r2, [sp, #4]
	ldr	r3, [sp, #16]
	str	r3, [r2]
	.loc 22 176 0
	ldr	r3, [sp, #20]
	str	r3, [r2, #4]
	.loc 22 177 0
	ldr	r3, [sp, #24]
	str	r3, [r2, #8]
	.loc 22 178 0
	ldr	r3, [sp, #28]
.LBE6594:
.LBE6593:
.LBE6597:
	.loc 21 486 0
	add	sp, sp, #36
.LVL381:
	@ sp needed for prologue
.LBB6598:
.LBB6596:
.LBB6595:
	.loc 22 178 0
	str	r3, [r2, #12]
.LBE6595:
.LBE6596:
.LBE6598:
	.loc 21 486 0
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE274:
	.fnend
	.size	_ZNK11btMatrix3x311getRotationER12btQuaternion, .-_ZNK11btMatrix3x311getRotationER12btQuaternion
	.section	.text._ZNK11btMatrix3x35tdotxERK9btVector3,"axG",%progbits,_ZNK11btMatrix3x35tdotxERK9btVector3,comdat
	.align	1
	.weak	_ZNK11btMatrix3x35tdotxERK9btVector3
	.code	16
	.thumb_func
	.type	_ZNK11btMatrix3x35tdotxERK9btVector3, %function
_ZNK11btMatrix3x35tdotxERK9btVector3:
	.fnstart
.LFB278:
	.loc 21 616 0
	.cfi_startproc
	.save	{r4, r5, r6, lr}
	push	{r4, r5, r6, lr}
.LCFI59:
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
.LVL382:
	.loc 21 616 0
	mov	r5, r1
	mov	r4, r0
	.loc 21 618 0
	ldr	r1, [r1]
.LVL383:
	ldr	r0, [r0]
.LVL384:
	bl	__aeabi_fmul
	ldr	r1, [r5, #4]
	add	r6, r0, #0
	ldr	r0, [r4, #16]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r6, #0
	bl	__aeabi_fadd
	ldr	r1, [r5, #8]
	add	r6, r0, #0
	ldr	r0, [r4, #32]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r6, #0
	bl	__aeabi_fadd
	.loc 21 619 0
	@ sp needed for prologue
.LVL385:
.LVL386:
	pop	{r4, r5, r6, pc}
	.cfi_endproc
.LFE278:
	.fnend
	.size	_ZNK11btMatrix3x35tdotxERK9btVector3, .-_ZNK11btMatrix3x35tdotxERK9btVector3
	.section	.text._ZNK11btMatrix3x35tdotyERK9btVector3,"axG",%progbits,_ZNK11btMatrix3x35tdotyERK9btVector3,comdat
	.align	1
	.weak	_ZNK11btMatrix3x35tdotyERK9btVector3
	.code	16
	.thumb_func
	.type	_ZNK11btMatrix3x35tdotyERK9btVector3, %function
_ZNK11btMatrix3x35tdotyERK9btVector3:
	.fnstart
.LFB279:
	.loc 21 620 0
	.cfi_startproc
	.save	{r4, r5, r6, lr}
	push	{r4, r5, r6, lr}
.LCFI60:
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
.LVL387:
	.loc 21 620 0
	mov	r5, r1
	mov	r4, r0
	.loc 21 622 0
	ldr	r1, [r1]
.LVL388:
	ldr	r0, [r0, #4]
.LVL389:
	bl	__aeabi_fmul
	ldr	r1, [r5, #4]
	add	r6, r0, #0
	ldr	r0, [r4, #20]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r6, #0
	bl	__aeabi_fadd
	ldr	r1, [r5, #8]
	add	r6, r0, #0
	ldr	r0, [r4, #36]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r6, #0
	bl	__aeabi_fadd
	.loc 21 623 0
	@ sp needed for prologue
.LVL390:
.LVL391:
	pop	{r4, r5, r6, pc}
	.cfi_endproc
.LFE279:
	.fnend
	.size	_ZNK11btMatrix3x35tdotyERK9btVector3, .-_ZNK11btMatrix3x35tdotyERK9btVector3
	.section	.text._ZNK11btMatrix3x35tdotzERK9btVector3,"axG",%progbits,_ZNK11btMatrix3x35tdotzERK9btVector3,comdat
	.align	1
	.weak	_ZNK11btMatrix3x35tdotzERK9btVector3
	.code	16
	.thumb_func
	.type	_ZNK11btMatrix3x35tdotzERK9btVector3, %function
_ZNK11btMatrix3x35tdotzERK9btVector3:
	.fnstart
.LFB280:
	.loc 21 624 0
	.cfi_startproc
	.save	{r4, r5, r6, lr}
	push	{r4, r5, r6, lr}
.LCFI61:
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
.LVL392:
	.loc 21 624 0
	mov	r5, r1
	mov	r4, r0
	.loc 21 626 0
	ldr	r1, [r1]
.LVL393:
	ldr	r0, [r0, #8]
.LVL394:
	bl	__aeabi_fmul
	ldr	r1, [r5, #4]
	add	r6, r0, #0
	ldr	r0, [r4, #24]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r6, #0
	bl	__aeabi_fadd
	ldr	r1, [r5, #8]
	add	r6, r0, #0
	ldr	r0, [r4, #40]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r6, #0
	bl	__aeabi_fadd
	.loc 21 627 0
	@ sp needed for prologue
.LVL395:
.LVL396:
	pop	{r4, r5, r6, pc}
	.cfi_endproc
.LFE280:
	.fnend
	.size	_ZNK11btMatrix3x35tdotzERK9btVector3, .-_ZNK11btMatrix3x35tdotzERK9btVector3
	.section	.text._ZNK11btMatrix3x35cofacEiiii,"axG",%progbits,_ZNK11btMatrix3x35cofacEiiii,comdat
	.align	1
	.weak	_ZNK11btMatrix3x35cofacEiiii
	.code	16
	.thumb_func
	.type	_ZNK11btMatrix3x35cofacEiiii, %function
_ZNK11btMatrix3x35cofacEiiii:
	.fnstart
.LFB282:
	.loc 21 727 0
	.cfi_startproc
	.save	{r0, r1, r2, r4, r5, r6, r7, lr}
	push	{r0, r1, r2, r4, r5, r6, r7, lr}
.LCFI62:
	.cfi_def_cfa_offset 32
	.cfi_offset 0, -32
	.cfi_offset 1, -28
	.cfi_offset 2, -24
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL397:
	.loc 21 729 0
	ldr	r4, [sp, #32]
	lsl	r7, r3, #4
	lsl	r5, r1, #4
	lsl	r6, r2, #2
	add	r7, r0, r7
	add	r5, r0, r5
.LVL398:
	lsl	r4, r4, #2
	ldr	r0, [r6, r5]
.LVL399:
	ldr	r1, [r4, r7]
.LVL400:
	bl	__aeabi_fmul
.LVL401:
	ldr	r1, [r6, r7]
	str	r0, [sp, #4]
	ldr	r0, [r4, r5]
	bl	__aeabi_fmul
	add	r1, r0, #0
	ldr	r0, [sp, #4]
	bl	__aeabi_fsub
	.loc 21 730 0
	@ sp needed for prologue
.LVL402:
.LVL403:
	pop	{r1, r2, r3, r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE282:
	.fnend
	.size	_ZNK11btMatrix3x35cofacEiiii, .-_ZNK11btMatrix3x35cofacEiiii
	.section	.text._ZNK11btMatrix3x37inverseEv,"axG",%progbits,_ZNK11btMatrix3x37inverseEv,comdat
	.align	1
	.weak	_ZNK11btMatrix3x37inverseEv
	.code	16
	.thumb_func
	.type	_ZNK11btMatrix3x37inverseEv, %function
_ZNK11btMatrix3x37inverseEv:
	.fnstart
.LFB293:
	.loc 21 1026 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI63:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL404:
	.pad #60
	sub	sp, sp, #60
.LCFI64:
	.cfi_def_cfa_offset 80
	.loc 21 1026 0
	mov	r4, r0
.LBB6599:
	.loc 21 1027 0
	mov	r5, #2
.LBE6599:
	.loc 21 1026 0
	mov	r7, r1
.LBB6635:
	.loc 21 1027 0
	mov	r0, r1
.LVL405:
	mov	r1, #1
.LVL406:
	str	r5, [sp]
	mov	r2, r1
	mov	r3, r5
	bl	_ZNK11btMatrix3x35cofacEiiii
.LVL407:
	mov	r6, #0
	str	r6, [sp]
	str	r0, [sp, #12]
	mov	r2, r5
	mov	r0, r7
	mov	r3, r5
	mov	r1, #1
	bl	_ZNK11btMatrix3x35cofacEiiii
	mov	r3, #1
	mov	r2, r6
	str	r0, [sp, #16]
	str	r3, [sp]
	mov	r0, r7
	mov	r1, r3
	mov	r3, r5
	bl	_ZNK11btMatrix3x35cofacEiiii
.LBB6600:
.LBB6601:
.LBB6602:
	.loc 15 132 0
	ldr	r3, [sp, #12]
.LBE6602:
.LBE6601:
.LBE6600:
	.loc 21 1027 0
	str	r0, [sp, #20]
.LVL408:
.LBB6607:
.LBB6605:
.LBB6603:
	.loc 15 134 0
	str	r0, [sp, #48]
	.loc 15 132 0
	str	r3, [sp, #40]
	.loc 15 133 0
	ldr	r3, [sp, #16]
.LBE6603:
.LBE6605:
.LBE6607:
	.loc 21 1028 0
	mov	r0, r7
	add	r1, sp, #40
.LBB6608:
.LBB6606:
.LBB6604:
	.loc 15 133 0
	str	r3, [sp, #44]
	.loc 15 135 0
	mov	r3, #0
	str	r3, [sp, #52]
.LVL409:
.LBE6604:
.LBE6606:
.LBE6608:
	.loc 21 1028 0
	bl	_ZNK9btVector33dotERKS_
	add	r1, r0, #0
.LVL410:
	.loc 21 1030 0
	mov	r0, #254
.LVL411:
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
.LVL412:
	str	r0, [sp, #8]
.LVL413:
	.loc 21 1033 0
	ldr	r1, [sp, #8]
	ldr	r0, [sp, #12]
.LVL414:
	bl	__aeabi_fmul
.LVL415:
	.loc 21 1031 0
	mov	r3, #1
	mov	r1, r6
	mov	r2, r5
	.loc 21 1033 0
	str	r0, [sp, #12]
	.loc 21 1031 0
	str	r3, [sp]
	mov	r0, r7
	mov	r3, r5
	bl	_ZNK11btMatrix3x35cofacEiiii
	.loc 21 1033 0
	ldr	r1, [sp, #8]
	bl	__aeabi_fmul
	.loc 21 1031 0
	mov	r2, #1
	mov	r3, r2
	mov	r1, r6
	.loc 21 1033 0
	str	r0, [sp, #24]
	.loc 21 1031 0
	str	r5, [sp]
	mov	r0, r7
	bl	_ZNK11btMatrix3x35cofacEiiii
	.loc 21 1033 0
	ldr	r1, [sp, #8]
	bl	__aeabi_fmul
	ldr	r1, [sp, #8]
	str	r0, [sp, #28]
.LVL416:
	ldr	r0, [sp, #16]
	bl	__aeabi_fmul
	.loc 21 1032 0
	mov	r2, r6
	mov	r1, r6
	mov	r3, r5
	.loc 21 1033 0
	str	r0, [sp, #16]
	.loc 21 1032 0
	str	r5, [sp]
	mov	r0, r7
	bl	_ZNK11btMatrix3x35cofacEiiii
	.loc 21 1033 0
	ldr	r1, [sp, #8]
	bl	__aeabi_fmul
	.loc 21 1032 0
	mov	r2, r5
	str	r6, [sp]
	mov	r1, r6
	mov	r3, #1
	.loc 21 1033 0
	str	r0, [sp, #32]
	.loc 21 1032 0
	mov	r0, r7
	bl	_ZNK11btMatrix3x35cofacEiiii
	.loc 21 1033 0
	ldr	r1, [sp, #8]
	bl	__aeabi_fmul
	ldr	r1, [sp, #8]
	str	r0, [sp, #36]
.LVL417:
	ldr	r0, [sp, #20]
	bl	__aeabi_fmul
	mov	r1, r6
	str	r0, [sp, #20]
	mov	r3, r5
	str	r6, [sp]
	mov	r0, r7
	mov	r2, #1
	bl	_ZNK11btMatrix3x35cofacEiiii
	ldr	r1, [sp, #8]
	bl	__aeabi_fmul
	mov	r3, #1
	add	r5, r0, #0
	mov	r1, r6
	mov	r2, r6
	str	r3, [sp]
	mov	r0, r7
	bl	_ZNK11btMatrix3x35cofacEiiii
.LVL418:
.LBB6609:
.LBB6610:
.LBB6611:
.LBB6612:
.LBB6613:
	.loc 15 632 0
	ldr	r3, [sp, #12]
.LBE6613:
.LBE6612:
.LBB6615:
.LBB6616:
	.loc 15 633 0
	str	r5, [r4, #36]
.LBE6616:
.LBE6615:
.LBE6611:
.LBE6610:
.LBE6609:
	.loc 21 1033 0
	ldr	r1, [sp, #8]
.LBB6632:
.LBB6629:
.LBB6626:
.LBB6620:
.LBB6614:
	.loc 15 632 0
	str	r3, [r4]
	.loc 15 633 0
	ldr	r3, [sp, #24]
	str	r3, [r4, #4]
	.loc 15 634 0
	ldr	r3, [sp, #28]
	str	r3, [r4, #8]
	.loc 15 635 0
	mov	r3, #0
	str	r3, [r4, #12]
.LVL419:
.LBE6614:
.LBE6620:
.LBB6621:
.LBB6622:
	.loc 15 632 0
	ldr	r3, [sp, #16]
	str	r3, [r4, #16]
	.loc 15 633 0
	ldr	r3, [sp, #32]
	str	r3, [r4, #20]
	.loc 15 634 0
	ldr	r3, [sp, #36]
	str	r3, [r4, #24]
	.loc 15 635 0
	mov	r3, #0
	str	r3, [r4, #28]
.LVL420:
.LBE6622:
.LBE6621:
.LBB6623:
.LBB6617:
	.loc 15 632 0
	ldr	r3, [sp, #20]
	str	r3, [r4, #32]
.LBE6617:
.LBE6623:
.LBE6626:
.LBE6629:
.LBE6632:
	.loc 21 1033 0
	bl	__aeabi_fmul
.LBB6633:
.LBB6630:
.LBB6627:
.LBB6624:
.LBB6618:
	.loc 15 635 0
	mov	r3, #0
.LBE6618:
.LBE6624:
.LBE6627:
.LBE6630:
.LBE6633:
.LBE6635:
	.loc 21 1034 0
	add	sp, sp, #60
.LBB6636:
.LBB6634:
.LBB6631:
.LBB6628:
.LBB6625:
.LBB6619:
	.loc 15 634 0
	str	r0, [r4, #40]
	.loc 15 635 0
	str	r3, [r4, #44]
.LBE6619:
.LBE6625:
.LBE6628:
.LBE6631:
.LBE6634:
.LBE6636:
	.loc 21 1034 0
	mov	r0, r4
	@ sp needed for prologue
.LVL421:
.LVL422:
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE293:
	.fnend
	.size	_ZNK11btMatrix3x37inverseEv, .-_ZNK11btMatrix3x37inverseEv
	.section	.text._ZNK11btMatrix3x314transposeTimesERKS_,"axG",%progbits,_ZNK11btMatrix3x314transposeTimesERKS_,comdat
	.align	1
	.weak	_ZNK11btMatrix3x314transposeTimesERKS_
	.code	16
	.thumb_func
	.type	_ZNK11btMatrix3x314transposeTimesERKS_, %function
_ZNK11btMatrix3x314transposeTimesERKS_:
	.fnstart
.LFB294:
	.loc 21 1038 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI65:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL423:
	.loc 21 1088 0
	ldr	r3, [r2]
	.loc 21 1038 0
	.pad #68
	sub	sp, sp, #68
.LCFI66:
	.cfi_def_cfa_offset 88
	.loc 21 1088 0
	ldr	r7, [r1, #32]
	str	r3, [sp, #4]
	ldr	r3, [r2, #16]
	ldr	r5, [r1]
.LVL424:
	ldr	r6, [r1, #16]
.LVL425:
	str	r3, [sp, #8]
.LVL426:
	ldr	r3, [r2, #32]
	.loc 21 1038 0
	mov	r4, r0
	.loc 21 1088 0
	add	r0, r5, #0
.LVL427:
	str	r3, [sp, #12]
.LVL428:
	ldr	r3, [r2, #4]
	str	r3, [sp, #16]
.LVL429:
	ldr	r3, [r2, #20]
	str	r3, [sp, #20]
.LVL430:
	ldr	r3, [r2, #36]
	str	r3, [sp, #24]
.LVL431:
	ldr	r3, [r2, #8]
	str	r3, [sp, #28]
.LVL432:
	ldr	r3, [r2, #24]
	ldr	r2, [r2, #40]
.LVL433:
	str	r3, [sp, #32]
.LVL434:
	ldr	r3, [r1, #4]
	str	r2, [sp, #36]
.LVL435:
	str	r3, [sp, #40]
.LVL436:
	ldr	r3, [r1, #20]
	str	r3, [sp, #44]
.LVL437:
	ldr	r3, [r1, #36]
	str	r3, [sp, #48]
.LVL438:
	ldr	r3, [r1, #8]
	str	r3, [sp, #52]
.LVL439:
	ldr	r3, [r1, #24]
	ldr	r1, [r1, #40]
.LVL440:
	str	r3, [sp, #56]
.LVL441:
	str	r1, [sp, #60]
.LVL442:
	ldr	r1, [sp, #4]
	bl	__aeabi_fmul
	ldr	r1, [sp, #8]
	str	r0, [sp]
	add	r0, r6, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	ldr	r0, [sp]
	bl	__aeabi_fadd
	ldr	r1, [sp, #12]
	str	r0, [sp]
	add	r0, r7, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	ldr	r0, [sp]
	bl	__aeabi_fadd
	ldr	r1, [sp, #16]
.LBB6637:
.LBB6638:
.LBB6639:
.LBB6640:
.LBB6641:
	.loc 15 632 0
	str	r0, [r4]
.LBE6641:
.LBE6640:
.LBE6639:
.LBE6638:
.LBE6637:
	.loc 21 1088 0
	add	r0, r5, #0
	bl	__aeabi_fmul
	ldr	r1, [sp, #20]
	str	r0, [sp]
	add	r0, r6, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	ldr	r0, [sp]
	bl	__aeabi_fadd
	str	r0, [sp]
	ldr	r1, [sp, #24]
	add	r0, r7, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	ldr	r0, [sp]
	bl	__aeabi_fadd
	ldr	r1, [sp, #28]
.LBB6678:
.LBB6669:
.LBB6660:
.LBB6645:
.LBB6642:
	.loc 15 633 0
	str	r0, [r4, #4]
.LBE6642:
.LBE6645:
.LBE6660:
.LBE6669:
.LBE6678:
	.loc 21 1088 0
	add	r0, r5, #0
	bl	__aeabi_fmul
	ldr	r1, [sp, #32]
	add	r5, r0, #0
	add	r0, r6, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	ldr	r1, [sp, #36]
	add	r5, r0, #0
	add	r0, r7, #0
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
.LBB6679:
.LBB6670:
.LBB6661:
.LBB6646:
.LBB6643:
	.loc 15 635 0
	mov	r6, #0
.LBE6643:
.LBE6646:
.LBE6661:
.LBE6670:
.LBE6679:
	.loc 21 1088 0
	ldr	r1, [sp, #4]
.LBB6680:
.LBB6671:
.LBB6662:
.LBB6647:
.LBB6644:
	.loc 15 634 0
	str	r0, [r4, #8]
	.loc 15 635 0
	str	r6, [r4, #12]
.LVL443:
.LBE6644:
.LBE6647:
.LBE6662:
.LBE6671:
.LBE6680:
	.loc 21 1088 0
	ldr	r0, [sp, #40]
	bl	__aeabi_fmul
	ldr	r1, [sp, #8]
	add	r5, r0, #0
	ldr	r0, [sp, #44]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	ldr	r1, [sp, #12]
	add	r5, r0, #0
	ldr	r0, [sp, #48]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	ldr	r1, [sp, #16]
.LBB6681:
.LBB6672:
.LBB6663:
.LBB6648:
.LBB6649:
	.loc 15 632 0
	str	r0, [r4, #16]
.LBE6649:
.LBE6648:
.LBE6663:
.LBE6672:
.LBE6681:
	.loc 21 1088 0
	ldr	r0, [sp, #40]
	bl	__aeabi_fmul
	ldr	r1, [sp, #20]
	add	r5, r0, #0
	ldr	r0, [sp, #44]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	ldr	r1, [sp, #24]
	add	r5, r0, #0
	ldr	r0, [sp, #48]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
.LBB6682:
.LBB6673:
.LBB6664:
.LBB6652:
.LBB6650:
	.loc 15 633 0
	str	r0, [r4, #20]
.LBE6650:
.LBE6652:
.LBE6664:
.LBE6673:
.LBE6682:
	.loc 21 1088 0
	ldr	r1, [sp, #28]
	ldr	r0, [sp, #40]
	bl	__aeabi_fmul
	ldr	r1, [sp, #32]
	add	r5, r0, #0
	ldr	r0, [sp, #44]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	ldr	r1, [sp, #36]
	add	r5, r0, #0
	ldr	r0, [sp, #48]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	ldr	r1, [sp, #4]
.LBB6683:
.LBB6674:
.LBB6665:
.LBB6653:
.LBB6651:
	.loc 15 634 0
	str	r0, [r4, #24]
	.loc 15 635 0
	str	r6, [r4, #28]
.LVL444:
.LBE6651:
.LBE6653:
.LBE6665:
.LBE6674:
.LBE6683:
	.loc 21 1088 0
	ldr	r0, [sp, #52]
	bl	__aeabi_fmul
	ldr	r1, [sp, #8]
	add	r5, r0, #0
	ldr	r0, [sp, #56]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	ldr	r1, [sp, #12]
	add	r5, r0, #0
	ldr	r0, [sp, #60]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	ldr	r1, [sp, #16]
.LBB6684:
.LBB6675:
.LBB6666:
.LBB6654:
.LBB6655:
	.loc 15 632 0
	str	r0, [r4, #32]
.LBE6655:
.LBE6654:
.LBE6666:
.LBE6675:
.LBE6684:
	.loc 21 1088 0
	ldr	r0, [sp, #52]
	bl	__aeabi_fmul
	ldr	r1, [sp, #20]
	add	r5, r0, #0
	ldr	r0, [sp, #56]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	ldr	r1, [sp, #24]
	add	r5, r0, #0
	ldr	r0, [sp, #60]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
.LBB6685:
.LBB6676:
.LBB6667:
.LBB6658:
.LBB6656:
	.loc 15 633 0
	str	r0, [r4, #36]
.LBE6656:
.LBE6658:
.LBE6667:
.LBE6676:
.LBE6685:
	.loc 21 1088 0
	ldr	r1, [sp, #28]
	ldr	r0, [sp, #52]
	bl	__aeabi_fmul
	ldr	r1, [sp, #32]
	add	r5, r0, #0
	ldr	r0, [sp, #56]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	ldr	r1, [sp, #36]
	add	r5, r0, #0
	ldr	r0, [sp, #60]
	bl	__aeabi_fmul
	add	r1, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fadd
	.loc 21 1090 0
	add	sp, sp, #68
.LBB6686:
.LBB6677:
.LBB6668:
.LBB6659:
.LBB6657:
	.loc 15 634 0
	str	r0, [r4, #40]
	.loc 15 635 0
	str	r6, [r4, #44]
.LBE6657:
.LBE6659:
.LBE6668:
.LBE6677:
.LBE6686:
	.loc 21 1090 0
	mov	r0, r4
	@ sp needed for prologue
.LVL445:
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE294:
	.fnend
	.size	_ZNK11btMatrix3x314transposeTimesERKS_, .-_ZNK11btMatrix3x314transposeTimesERKS_
	.section	.text._ZmlRK11btMatrix3x3RK9btVector3,"axG",%progbits,_ZmlRK11btMatrix3x3RK9btVector3,comdat
	.align	1
	.weak	_ZmlRK11btMatrix3x3RK9btVector3
	.code	16
	.thumb_func
	.type	_ZmlRK11btMatrix3x3RK9btVector3, %function
_ZmlRK11btMatrix3x3RK9btVector3:
	.fnstart
.LFB296:
	.loc 21 1147 0
	.cfi_startproc
	.save	{r0, r1, r2, r4, r5, r6, r7, lr}
	push	{r0, r1, r2, r4, r5, r6, r7, lr}
.LCFI67:
	.cfi_def_cfa_offset 32
	.cfi_offset 0, -32
	.cfi_offset 1, -28
	.cfi_offset 2, -24
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL446:
	.loc 21 1147 0
	mov	r4, r0
	mov	r5, r1
	.loc 21 1151 0
	mov	r0, r1
.LVL447:
	mov	r1, r2
.LVL448:
	.loc 21 1147 0
	mov	r6, r2
	.loc 21 1151 0
	bl	_ZNK9btVector33dotERKS_
.LVL449:
	add	r7, r0, #0
.LVL450:
	mov	r0, r5
	mov	r1, r6
	add	r0, r0, #16
	bl	_ZNK9btVector33dotERKS_
	str	r0, [sp, #4]
.LVL451:
	mov	r0, r5
	mov	r1, r6
	add	r0, r0, #32
	bl	_ZNK9btVector33dotERKS_
.LVL452:
.LBB6687:
.LBB6688:
.LBB6689:
	.loc 15 133 0
	ldr	r3, [sp, #4]
	.loc 15 132 0
	str	r7, [r4]
	.loc 15 134 0
	str	r0, [r4, #8]
	.loc 15 133 0
	str	r3, [r4, #4]
	.loc 15 135 0
	mov	r3, #0
.LBE6689:
.LBE6688:
.LBE6687:
	.loc 21 1153 0
	mov	r0, r4
.LBB6692:
.LBB6691:
.LBB6690:
	.loc 15 135 0
	str	r3, [r4, #12]
.LBE6690:
.LBE6691:
.LBE6692:
	.loc 21 1153 0
	@ sp needed for prologue
.LVL453:
.LVL454:
.LVL455:
	pop	{r1, r2, r3, r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE296:
	.fnend
	.size	_ZmlRK11btMatrix3x3RK9btVector3, .-_ZmlRK11btMatrix3x3RK9btVector3
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallback9reportHitERK9btVector3fii,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallback9reportHitERK9btVector3fii, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallback9reportHitERK9btVector3fii:
	.fnstart
.LFB1516:
	.loc 8 358 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI68:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL456:
	.pad #68
	sub	sp, sp, #68
.LCFI69:
	.cfi_def_cfa_offset 88
.LBB6693:
	.loc 8 361 0
	str	r3, [sp, #12]
	.loc 8 362 0
	ldr	r3, [sp, #88]
.LVL457:
.LBE6693:
	.loc 8 358 0
	mov	r6, r1
.LBB6706:
	.loc 8 364 0
	add	r7, sp, #20
	mov	r1, r0
.LVL458:
.LBE6706:
	.loc 8 358 0
	mov	r4, r0
	str	r2, [sp, #4]
.LBB6707:
	.loc 8 364 0
	add	r1, r1, #56
	mov	r2, r6
.LVL459:
	mov	r0, r7
.LVL460:
	.loc 8 362 0
	str	r3, [sp, #16]
	.loc 8 364 0
	bl	_ZmlRK11btMatrix3x3RK9btVector3
.LVL461:
.LBB6694:
.LBB6695:
.LBB6696:
	.loc 4 185 0
	ldr	r3, [r4, #48]
.LBE6696:
.LBE6695:
.LBE6694:
	.loc 8 361 0
	add	r5, sp, #12
.LBB6703:
.LBB6700:
.LBB6697:
	.loc 4 185 0
	str	r5, [sp, #40]
	str	r3, [sp, #36]
	add	r3, sp, #44
	ldmia	r7!, {r0, r1, r2}
	stmia	r3!, {r0, r1, r2}
.LVL462:
	ldr	r2, [r7]
.LBE6697:
.LBE6700:
.LBE6703:
	.loc 8 373 0
	add	r1, sp, #36
.LBB6704:
.LBB6701:
.LBB6698:
	.loc 4 185 0
	str	r2, [r3]
	ldr	r3, [sp, #4]
.LBE6698:
.LBE6701:
.LBE6704:
	.loc 8 373 0
	ldr	r0, [r4, #44]
	mov	r2, #1
.LBB6705:
.LBB6702:
.LBB6699:
	.loc 4 185 0
	str	r3, [sp, #60]
.LVL463:
.LBE6699:
.LBE6702:
.LBE6705:
	.loc 8 373 0
	ldr	r3, [r0]
	ldr	r3, [r3, #12]
	blx	r3
.LVL464:
.LBE6707:
	.loc 8 374 0
	add	sp, sp, #68
	@ sp needed for prologue
.LVL465:
.LVL466:
.LVL467:
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE1516:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallback9reportHitERK9btVector3fii, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallback9reportHitERK9btVector3fii
	.section	.text._ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallback9reportHitE_0RK9btVector3fii,"ax",%progbits
	.align	1
	.code	16
	.thumb_func
	.type	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallback9reportHitE_0RK9btVector3fii, %function
_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallback9reportHitE_0RK9btVector3fii:
	.fnstart
.LFB1524:
	.loc 8 413 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI70:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL468:
	.pad #68
	sub	sp, sp, #68
.LCFI71:
	.cfi_def_cfa_offset 88
.LBB6708:
	.loc 8 416 0
	str	r3, [sp, #12]
	.loc 8 417 0
	ldr	r3, [sp, #88]
.LVL469:
.LBE6708:
	.loc 8 413 0
	mov	r6, r1
.LBB6721:
	.loc 8 419 0
	add	r7, sp, #20
	mov	r1, r0
.LVL470:
.LBE6721:
	.loc 8 413 0
	mov	r4, r0
	str	r2, [sp, #4]
.LBB6722:
	.loc 8 419 0
	add	r1, r1, #56
	mov	r2, r6
.LVL471:
	mov	r0, r7
.LVL472:
	.loc 8 417 0
	str	r3, [sp, #16]
	.loc 8 419 0
	bl	_ZmlRK11btMatrix3x3RK9btVector3
.LVL473:
.LBB6709:
.LBB6710:
.LBB6711:
	.loc 4 185 0
	ldr	r3, [r4, #48]
.LBE6711:
.LBE6710:
.LBE6709:
	.loc 8 416 0
	add	r5, sp, #12
.LBB6718:
.LBB6715:
.LBB6712:
	.loc 4 185 0
	str	r5, [sp, #40]
	str	r3, [sp, #36]
	add	r3, sp, #44
	ldmia	r7!, {r0, r1, r2}
	stmia	r3!, {r0, r1, r2}
.LVL474:
	ldr	r2, [r7]
.LBE6712:
.LBE6715:
.LBE6718:
	.loc 8 428 0
	add	r1, sp, #36
.LBB6719:
.LBB6716:
.LBB6713:
	.loc 4 185 0
	str	r2, [r3]
	ldr	r3, [sp, #4]
.LBE6713:
.LBE6716:
.LBE6719:
	.loc 8 428 0
	ldr	r0, [r4, #44]
	mov	r2, #1
.LBB6720:
.LBB6717:
.LBB6714:
	.loc 4 185 0
	str	r3, [sp, #60]
.LVL475:
.LBE6714:
.LBE6717:
.LBE6720:
	.loc 8 428 0
	ldr	r3, [r0]
	ldr	r3, [r3, #12]
	blx	r3
.LVL476:
.LBE6722:
	.loc 8 429 0
	add	sp, sp, #68
	@ sp needed for prologue
.LVL477:
.LVL478:
.LVL479:
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE1524:
	.fnend
	.size	_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallback9reportHitE_0RK9btVector3fii, .-_ZZN16btCollisionWorld21rayTestSingleInternalERK11btTransformS2_PK24btCollisionObjectWrapperRNS_17RayResultCallbackEEN29BridgeTriangleRaycastCallback9reportHitE_0RK9btVector3fii
	.section	.text._ZmlRK11btMatrix3x3S1_,"axG",%progbits,_ZmlRK11btMatrix3x3S1_,comdat
	.align	1
	.weak	_ZmlRK11btMatrix3x3S1_
	.code	16
	.thumb_func
	.type	_ZmlRK11btMatrix3x3S1_, %function
_ZmlRK11btMatrix3x3S1_:
	.fnstart
.LFB298:
	.loc 21 1198 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI72:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL480:
	.pad #36
	sub	sp, sp, #36
.LCFI73:
	.cfi_def_cfa_offset 56
	.loc 21 1198 0
	mov	r5, r0
	.loc 21 1275 0
	mov	r0, r2
.LVL481:
	.loc 21 1198 0
	mov	r6, r2
	mov	r7, r1
	.loc 21 1275 0
	bl	_ZNK11btMatrix3x35tdotxERK9btVector3
.LVL482:
	mov	r1, r7
	str	r0, [sp, #4]
.LVL483:
	mov	r0, r6
	bl	_ZNK11btMatrix3x35tdotyERK9btVector3
	mov	r1, r7
	str	r0, [sp, #8]
.LVL484:
	mov	r0, r6
	bl	_ZNK11btMatrix3x35tdotzERK9btVector3
	.loc 21 1276 0
	mov	r4, r7
	add	r4, r4, #16
.LVL485:
	.loc 21 1275 0
	str	r0, [sp, #12]
.LVL486:
	.loc 21 1276 0
	mov	r1, r4
	mov	r0, r6
	bl	_ZNK11btMatrix3x35tdotxERK9btVector3
	mov	r1, r4
	str	r0, [sp, #16]
.LVL487:
	mov	r0, r6
	bl	_ZNK11btMatrix3x35tdotyERK9btVector3
	mov	r1, r4
	str	r0, [sp, #20]
.LVL488:
	mov	r0, r6
	bl	_ZNK11btMatrix3x35tdotzERK9btVector3
	.loc 21 1277 0
	add	r4, r4, #16
	.loc 21 1276 0
	str	r0, [sp, #24]
.LVL489:
	.loc 21 1277 0
	mov	r1, r4
	mov	r0, r6
	bl	_ZNK11btMatrix3x35tdotxERK9btVector3
	mov	r1, r4
	add	r7, r0, #0
.LVL490:
	mov	r0, r6
	bl	_ZNK11btMatrix3x35tdotyERK9btVector3
	mov	r1, r4
	str	r0, [sp, #28]
.LVL491:
	mov	r0, r6
	bl	_ZNK11btMatrix3x35tdotzERK9btVector3
.LVL492:
.LBB6723:
.LBB6724:
.LBB6725:
.LBB6726:
.LBB6727:
	.loc 15 632 0
	ldr	r2, [sp, #4]
	.loc 15 633 0
	ldr	r3, [sp, #8]
.LBE6727:
.LBE6726:
.LBB6730:
.LBB6731:
	.loc 15 632 0
	str	r7, [r5, #32]
.LBE6731:
.LBE6730:
.LBB6736:
.LBB6728:
	str	r2, [r5]
	.loc 15 634 0
	ldr	r2, [sp, #12]
	.loc 15 633 0
	str	r3, [r5, #4]
	.loc 15 635 0
	mov	r3, #0
	.loc 15 634 0
	str	r2, [r5, #8]
.LBE6728:
.LBE6736:
.LBB6737:
.LBB6738:
	.loc 15 632 0
	ldr	r2, [sp, #16]
.LBE6738:
.LBE6737:
.LBB6742:
.LBB6732:
	.loc 15 634 0
	str	r0, [r5, #40]
.LBE6732:
.LBE6742:
.LBB6743:
.LBB6729:
	.loc 15 635 0
	str	r3, [r5, #12]
.LVL493:
.LBE6729:
.LBE6743:
.LBB6744:
.LBB6739:
	.loc 15 632 0
	str	r2, [r5, #16]
	.loc 15 633 0
	ldr	r2, [sp, #20]
.LBE6739:
.LBE6744:
.LBE6725:
.LBE6724:
.LBE6723:
	.loc 21 1279 0
	mov	r0, r5
.LBB6754:
.LBB6752:
.LBB6750:
.LBB6745:
.LBB6740:
	.loc 15 635 0
	str	r3, [r5, #28]
.LVL494:
	.loc 15 633 0
	str	r2, [r5, #20]
	.loc 15 634 0
	ldr	r2, [sp, #24]
.LBE6740:
.LBE6745:
.LBB6746:
.LBB6733:
	.loc 15 635 0
	str	r3, [r5, #44]
.LBE6733:
.LBE6746:
.LBB6747:
.LBB6741:
	.loc 15 634 0
	str	r2, [r5, #24]
.LBE6741:
.LBE6747:
.LBB6748:
.LBB6734:
	.loc 15 633 0
	ldr	r2, [sp, #28]
.LBE6734:
.LBE6748:
.LBE6750:
.LBE6752:
.LBE6754:
	.loc 21 1279 0
	add	sp, sp, #36
	@ sp needed for prologue
.LBB6755:
.LBB6753:
.LBB6751:
.LBB6749:
.LBB6735:
	.loc 15 633 0
	str	r2, [r5, #36]
.LVL495:
.LVL496:
.LVL497:
.LBE6735:
.LBE6749:
.LBE6751:
.LBE6753:
.LBE6755:
	.loc 21 1279 0
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE298:
	.fnend
	.size	_ZmlRK11btMatrix3x3S1_, .-_ZmlRK11btMatrix3x3S1_
	.section	.text._ZN11btTransformC2ERKS_,"axG",%progbits,_ZN11btTransformC5ERKS_,comdat
	.align	1
	.weak	_ZN11btTransformC2ERKS_
	.code	16
	.thumb_func
	.type	_ZN11btTransformC2ERKS_, %function
_ZN11btTransformC2ERKS_:
	.fnstart
.LFB315:
	.file 23 "jni/../../../bullet4droid/jni/src/LinearMath/btTransform.h"
	.loc 23 63 0
	.cfi_startproc
	.save	{r3, r4, r5, lr}
	push	{r3, r4, r5, lr}
.LCFI74:
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	.cfi_offset 4, -12
	.cfi_offset 5, -8
	.cfi_offset 14, -4
.LVL498:
	.loc 23 63 0
	mov	r5, r0
	mov	r4, r1
.LBB6756:
	.loc 23 65 0
	bl	_ZN11btMatrix3x3C1ERKS_
.LVL499:
	mov	r3, r5
	add	r3, r3, #48
	add	r4, r4, #48
.LVL500:
	ldmia	r4!, {r0, r1, r2}
	stmia	r3!, {r0, r1, r2}
.LVL501:
	ldr	r2, [r4]
.LBE6756:
	.loc 23 67 0
	mov	r0, r5
	@ sp needed for prologue
.LBB6757:
	.loc 23 65 0
	str	r2, [r3]
.LVL502:
.LVL503:
.LBE6757:
	.loc 23 67 0
	pop	{r3, r4, r5, pc}
	.cfi_endproc
.LFE315:
	.fnend
	.size	_ZN11btTransformC2ERKS_, .-_ZN11btTransformC2ERKS_
	.section	.text._ZNK11btTransformclERK9btVector3,"axG",%progbits,_ZNK11btTransformclERK9btVector3,comdat
	.align	1
	.weak	_ZNK11btTransformclERK9btVector3
	.code	16
	.thumb_func
	.type	_ZNK11btTransformclERK9btVector3, %function
_ZNK11btTransformclERK9btVector3:
	.fnstart
.LFB319:
	.loc 23 94 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI75:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL504:
	.pad #28
	sub	sp, sp, #28
.LCFI76:
	.cfi_def_cfa_offset 48
	.loc 23 94 0
	mov	r6, r0
.LBB6758:
.LBB6759:
	.loc 15 735 0
	mov	r0, r2
.LVL505:
.LBE6759:
.LBE6758:
	.loc 23 94 0
	mov	r5, r2
	mov	r4, r1
.LBB6776:
.LBB6772:
	.loc 15 735 0
	bl	_ZNK9btVector33dotERKS_
.LVL506:
	.loc 23 96 0
	mov	r1, r4
	.loc 15 735 0
	add	r7, r0, #0
	.loc 23 96 0
	add	r1, r1, #16
	.loc 15 735 0
	mov	r0, r5
	bl	_ZNK9btVector33dotERKS_
	.loc 23 96 0
	mov	r1, r4
	.loc 15 735 0
	str	r0, [sp, #4]
	.loc 23 96 0
	add	r1, r1, #32
	.loc 15 735 0
	mov	r0, r5
	bl	_ZNK9btVector33dotERKS_
.LVL507:
.LBB6760:
.LBB6761:
.LBB6762:
	.loc 15 133 0
	ldr	r3, [sp, #4]
.LBE6762:
.LBE6761:
.LBE6760:
.LBE6772:
.LBE6776:
	.loc 23 96 0
	mov	r2, r4
.LBB6777:
.LBB6773:
.LBB6769:
.LBB6766:
.LBB6763:
	.loc 15 134 0
	str	r0, [sp, #16]
	.loc 15 133 0
	str	r3, [sp, #12]
.LBE6763:
.LBE6766:
.LBE6769:
.LBE6773:
.LBE6777:
	.loc 23 96 0
	mov	r0, r6
.LBB6778:
.LBB6774:
.LBB6770:
.LBB6767:
.LBB6764:
	.loc 15 135 0
	mov	r3, #0
.LBE6764:
.LBE6767:
.LBE6770:
.LBE6774:
.LBE6778:
	.loc 23 96 0
	add	r1, sp, #8
	add	r2, r2, #48
.LBB6779:
.LBB6775:
.LBB6771:
.LBB6768:
.LBB6765:
	.loc 15 132 0
	str	r7, [sp, #8]
	.loc 15 135 0
	str	r3, [sp, #20]
.LBE6765:
.LBE6768:
.LBE6771:
.LBE6775:
.LBE6779:
	.loc 23 96 0
	bl	_ZplRK9btVector3S1_
	.loc 23 97 0
	add	sp, sp, #28
	mov	r0, r6
	@ sp needed for prologue
.LVL508:
.LVL509:
.LVL510:
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE319:
	.fnend
	.size	_ZNK11btTransformclERK9btVector3, .-_ZNK11btTransformclERK9btVector3
	.section	.text._ZN17DebugDrawcallback15processTriangleEP9btVector3ii,"axG",%progbits,_ZN17DebugDrawcallback15processTriangleEP9btVector3ii,comdat
	.align	1
	.weak	_ZN17DebugDrawcallback15processTriangleEP9btVector3ii
	.code	16
	.thumb_func
	.type	_ZN17DebugDrawcallback15processTriangleEP9btVector3ii, %function
_ZN17DebugDrawcallback15processTriangleEP9btVector3ii:
	.fnstart
.LFB1641:
	.loc 8 1210 0
	.cfi_startproc
	.save	{r4, r5, r6, lr}
	push	{r4, r5, r6, lr}
.LCFI77:
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
.LVL511:
.LBB6780:
	.loc 8 1216 0
	mov	r6, r0
.LBE6780:
	.loc 8 1210 0
	.pad #176
	sub	sp, sp, #176
.LCFI78:
	.cfi_def_cfa_offset 192
.LVL512:
	.loc 8 1210 0
	mov	r4, r1
.LBB6809:
	.loc 8 1216 0
	add	r6, r6, #28
.LVL513:
.LBB6781:
.LBB6782:
	.loc 23 102 0
	mov	r1, r6
.LVL514:
	mov	r2, r4
.LVL515:
.LBE6782:
.LBE6781:
.LBE6809:
	.loc 8 1210 0
	mov	r5, r0
.LBB6810:
.LBB6784:
.LBB6783:
	.loc 23 102 0
	add	r0, sp, #160
.LVL516:
	bl	_ZNK11btTransformclERK9btVector3
.LVL517:
	.loc 8 1216 0
	add	r1, sp, #160
	mov	r2, #16
	mov	r0, sp
	bl	memcpy
.LVL518:
.LBE6783:
.LBE6784:
	.loc 8 1217 0
	mov	r2, r4
.LBB6785:
.LBB6786:
	.loc 23 102 0
	mov	r1, r6
.LBE6786:
.LBE6785:
	.loc 8 1217 0
	add	r2, r2, #16
.LBB6788:
.LBB6787:
	.loc 23 102 0
	add	r0, sp, #160
	bl	_ZNK11btTransformclERK9btVector3
	.loc 8 1217 0
	add	r1, sp, #160
	mov	r2, #16
	add	r0, sp, #16
	bl	memcpy
.LVL519:
.LBE6787:
.LBE6788:
	.loc 8 1218 0
	mov	r2, r4
.LBB6789:
.LBB6790:
	.loc 23 102 0
	mov	r1, r6
.LBE6790:
.LBE6789:
	.loc 8 1218 0
	add	r2, r2, #32
.LBB6792:
.LBB6791:
	.loc 23 102 0
	add	r0, sp, #160
	bl	_ZNK11btTransformclERK9btVector3
	.loc 8 1218 0
	add	r1, sp, #160
	mov	r2, #16
	add	r0, sp, #32
	bl	memcpy
.LBE6791:
.LBE6792:
	.loc 8 1219 0
	add	r0, sp, #64
	mov	r1, sp
	add	r2, sp, #16
	bl	_ZplRK9btVector3S1_
	add	r2, sp, #32
	add	r0, sp, #80
	add	r1, sp, #64
	bl	_ZplRK9btVector3S1_
.LVL520:
.LBB6793:
.LBB6794:
	.loc 15 818 0
	ldr	r1, .L380
	ldr	r0, [sp, #84]
	bl	__aeabi_fmul
	ldr	r1, .L380
	add	r4, r0, #0
.LVL521:
	ldr	r0, [sp, #88]
	bl	__aeabi_fmul
	ldr	r1, .L380
	add	r6, r0, #0
.LVL522:
	ldr	r0, [sp, #80]
	bl	__aeabi_fmul
.LBB6795:
.LBB6796:
.LBB6797:
	.loc 15 132 0
	str	r0, [sp, #48]
.LBE6797:
.LBE6796:
.LBE6795:
.LBE6794:
.LBE6793:
.LBB6802:
	.loc 8 1221 0
	ldr	r0, [r5, #8]
.LBE6802:
.LBB6807:
.LBB6801:
.LBB6800:
.LBB6799:
.LBB6798:
	.loc 15 133 0
	str	r4, [sp, #52]
	.loc 15 135 0
	mov	r4, #0
	.loc 15 134 0
	str	r6, [sp, #56]
	.loc 15 135 0
	str	r4, [sp, #60]
.LBE6798:
.LBE6799:
.LBE6800:
.LBE6801:
.LBE6807:
.LBB6808:
	.loc 8 1221 0
	ldr	r3, [r0]
	ldr	r3, [r3, #48]
	blx	r3
	lsl	r3, r0, #17
	bpl	.L378
.LBB6803:
	.loc 8 1223 0
	add	r0, sp, #112
	add	r1, sp, #16
	mov	r2, sp
	bl	_ZmiRK9btVector3S1_
	add	r0, sp, #128
	add	r1, sp, #32
	mov	r2, sp
	bl	_ZmiRK9btVector3S1_
	add	r1, sp, #112
	add	r2, sp, #128
	add	r0, sp, #96
	bl	_ZNK9btVector35crossERKS_
	.loc 8 1224 0
	add	r0, sp, #96
	bl	_ZN9btVector39normalizeEv
.LVL523:
	.loc 8 1226 0
	ldr	r6, [r5, #8]
.LBB6804:
.LBB6805:
.LBB6806:
	.loc 15 132 0
	mov	r3, #254
	lsl	r3, r3, #22
	str	r3, [sp, #160]
	.loc 15 133 0
	str	r3, [sp, #164]
	.loc 15 134 0
	str	r4, [sp, #168]
	.loc 15 135 0
	str	r4, [sp, #172]
.LBE6806:
.LBE6805:
.LBE6804:
	.loc 8 1226 0
	ldr	r3, [r6]
	add	r0, sp, #144
	add	r1, sp, #48
	add	r2, sp, #96
	ldr	r4, [r3, #8]
	bl	_ZplRK9btVector3S1_
	mov	r0, r6
	add	r1, sp, #48
	add	r2, sp, #144
	add	r3, sp, #160
.LVL524:
	blx	r4
.LVL525:
.L378:
.LBE6803:
.LBE6808:
	.loc 8 1228 0
	ldr	r0, [r5, #8]
	mov	r6, r5
	add	r6, r6, #12
	ldr	r3, [r0]
	mov	r1, sp
	add	r2, sp, #16
	ldr	r4, [r3, #8]
	mov	r3, r6
	blx	r4
	.loc 8 1229 0
	ldr	r0, [r5, #8]
	add	r1, sp, #16
	add	r2, sp, #32
	ldr	r3, [r0]
	ldr	r4, [r3, #8]
	mov	r3, r6
	blx	r4
	.loc 8 1230 0
	ldr	r0, [r5, #8]
	add	r1, sp, #32
	mov	r2, sp
	ldr	r3, [r0]
	ldr	r4, [r3, #8]
	mov	r3, r6
	blx	r4
.LBE6810:
	.loc 8 1231 0
	add	sp, sp, #176
.LVL526:
	@ sp needed for prologue
.LVL527:
.LVL528:
	pop	{r4, r5, r6, pc}
.L381:
	.align	2
.L380:
	.word	1051372203
	.cfi_endproc
.LFE1641:
	.fnend
	.size	_ZN17DebugDrawcallback15processTriangleEP9btVector3ii, .-_ZN17DebugDrawcallback15processTriangleEP9btVector3ii
	.section	.text._ZN11btTransform11setIdentityEv,"axG",%progbits,_ZN11btTransform11setIdentityEv,comdat
	.align	1
	.weak	_ZN11btTransform11setIdentityEv
	.code	16
	.thumb_func
	.type	_ZN11btTransform11setIdentityEv, %function
_ZN11btTransform11setIdentityEv:
	.fnstart
.LFB332:
	.loc 23 172 0
	.cfi_startproc
.LVL529:
.LBB6811:
.LBB6812:
.LBB6813:
.LBB6814:
	.loc 15 632 0
	mov	r2, #254
	.loc 15 633 0
	mov	r3, #0
	.loc 15 632 0
	lsl	r2, r2, #22
	str	r2, [r0]
	.loc 15 633 0
	str	r3, [r0, #4]
	.loc 15 634 0
	str	r3, [r0, #8]
	.loc 15 635 0
	str	r3, [r0, #12]
.LVL530:
.LBE6814:
.LBE6813:
.LBB6815:
.LBB6816:
	.loc 15 632 0
	str	r3, [r0, #16]
	.loc 15 633 0
	str	r2, [r0, #20]
	.loc 15 634 0
	str	r3, [r0, #24]
	.loc 15 635 0
	str	r3, [r0, #28]
.LVL531:
.LBE6816:
.LBE6815:
.LBB6817:
.LBB6818:
	.loc 15 632 0
	str	r3, [r0, #32]
	.loc 15 633 0
	str	r3, [r0, #36]
	.loc 15 634 0
	str	r2, [r0, #40]
	.loc 15 635 0
	str	r3, [r0, #44]
.LVL532:
.LBE6818:
.LBE6817:
.LBE6812:
.LBE6811:
.LBB6819:
.LBB6820:
	.loc 15 632 0
	str	r3, [r0, #48]
	.loc 15 633 0
	str	r3, [r0, #52]
	.loc 15 634 0
	str	r3, [r0, #56]
	.loc 15 635 0
	str	r3, [r0, #60]
.LBE6820:
.LBE6819:
	.loc 23 176 0
	@ sp needed for prologue
	bx	lr
	.cfi_endproc
.LFE332:
	.fnend
	.size	_ZN11btTransform11setIdentityEv, .-_ZN11btTransform11setIdentityEv
	.section	.text._ZNK11btTransform7inverseEv,"axG",%progbits,_ZNK11btTransform7inverseEv,comdat
	.align	1
	.weak	_ZNK11btTransform7inverseEv
	.code	16
	.thumb_func
	.type	_ZNK11btTransform7inverseEv, %function
_ZNK11btTransform7inverseEv:
	.fnstart
.LFB334:
	.loc 23 188 0
	.cfi_startproc
	.save	{r4, r5, lr}
	push	{r4, r5, lr}
.LCFI79:
	.cfi_def_cfa_offset 12
	.cfi_offset 4, -12
	.cfi_offset 5, -8
	.cfi_offset 14, -4
.LVL533:
.LBB6821:
.LBB6822:
.LBB6823:
.LBB6824:
.LBB6825:
.LBB6826:
.LBB6827:
	.loc 15 632 0
	ldr	r2, [r1, #4]
.LBE6827:
.LBE6826:
.LBE6825:
.LBE6824:
.LBE6823:
.LBE6822:
.LBE6821:
	.loc 23 188 0
	.pad #84
	sub	sp, sp, #84
.LCFI80:
	.cfi_def_cfa_offset 96
.LVL534:
.LBB6906:
.LBB6873:
.LBB6868:
.LBB6863:
.LBB6858:
.LBB6832:
.LBB6833:
	.loc 15 632 0
	ldr	r3, [r1]
.LBE6833:
.LBE6832:
.LBB6839:
.LBB6828:
	str	r2, [sp, #48]
	.loc 15 633 0
	ldr	r2, [r1, #20]
.LBE6828:
.LBE6839:
.LBE6858:
.LBE6863:
.LBE6868:
.LBE6873:
.LBE6906:
	.loc 23 188 0
	mov	r4, r0
.LBB6907:
.LBB6874:
.LBB6869:
.LBB6864:
.LBB6859:
.LBB6840:
.LBB6834:
	.loc 15 632 0
	str	r3, [sp, #32]
.LBE6834:
.LBE6840:
.LBB6841:
.LBB6829:
	.loc 15 633 0
	str	r2, [sp, #52]
	.loc 15 634 0
	ldr	r2, [r1, #36]
.LBE6829:
.LBE6841:
.LBB6842:
.LBB6835:
	.loc 15 633 0
	ldr	r3, [r1, #16]
.LBE6835:
.LBE6842:
.LBE6859:
.LBE6864:
.LBE6869:
.LBE6874:
.LBB6875:
.LBB6876:
	.loc 15 802 0
	ldr	r0, [r1, #52]
.LVL535:
.LBE6876:
.LBE6875:
.LBB6893:
.LBB6870:
.LBB6865:
.LBB6860:
.LBB6843:
.LBB6830:
	.loc 15 634 0
	str	r2, [sp, #56]
.LBE6830:
.LBE6843:
.LBB6844:
.LBB6845:
	.loc 15 632 0
	ldr	r2, [r1, #8]
.LBE6845:
.LBE6844:
.LBB6850:
.LBB6836:
	.loc 15 633 0
	str	r3, [sp, #36]
	.loc 15 634 0
	ldr	r3, [r1, #32]
.LBE6836:
.LBE6850:
.LBB6851:
.LBB6846:
	.loc 15 632 0
	str	r2, [sp, #64]
	.loc 15 633 0
	ldr	r2, [r1, #24]
.LBE6846:
.LBE6851:
.LBE6860:
.LBE6865:
.LBE6870:
.LBE6893:
.LBB6894:
.LBB6889:
	.loc 15 802 0
	mov	r5, #128
	lsl	r5, r5, #24
.LBE6889:
.LBE6894:
.LBB6895:
.LBB6871:
.LBB6866:
.LBB6861:
.LBB6852:
.LBB6847:
	.loc 15 633 0
	str	r2, [sp, #68]
	.loc 15 634 0
	ldr	r2, [r1, #40]
.LBE6847:
.LBE6852:
.LBB6853:
.LBB6837:
	str	r3, [sp, #40]
	.loc 15 635 0
	mov	r3, #0
.LBE6837:
.LBE6853:
.LBB6854:
.LBB6848:
	.loc 15 634 0
	str	r2, [sp, #72]
.LBE6848:
.LBE6854:
.LBE6861:
.LBE6866:
.LBE6871:
.LBE6895:
.LBB6896:
.LBB6890:
	.loc 15 802 0
	mov	r2, #128
	lsl	r2, r2, #24
	add	r0, r0, r2
	ldr	r2, [r1, #56]
	ldr	r1, [r1, #48]
.LVL536:
.LBB6877:
.LBB6878:
.LBB6879:
	.loc 15 133 0
	str	r0, [sp, #4]
.LBE6879:
.LBE6878:
.LBE6877:
	.loc 15 802 0
	add	r2, r2, r5
.LBB6886:
.LBB6883:
.LBB6880:
	.loc 15 132 0
	add	r1, r1, r5
.LBE6880:
.LBE6883:
.LBE6886:
.LBE6890:
.LBE6896:
	.loc 23 191 0
	add	r5, sp, #16
.LBB6897:
.LBB6891:
.LBB6887:
.LBB6884:
.LBB6881:
	.loc 15 132 0
	str	r1, [sp]
	.loc 15 134 0
	str	r2, [sp, #8]
.LBE6881:
.LBE6884:
.LBE6887:
.LBE6891:
.LBE6897:
	.loc 23 191 0
	mov	r0, r5
	mov	r2, sp
	add	r1, sp, #32
.LBB6898:
.LBB6872:
.LBB6867:
.LBB6862:
.LBB6855:
.LBB6838:
	.loc 15 635 0
	str	r3, [sp, #44]
.LVL537:
.LBE6838:
.LBE6855:
.LBB6856:
.LBB6831:
	str	r3, [sp, #60]
.LVL538:
.LBE6831:
.LBE6856:
.LBB6857:
.LBB6849:
	str	r3, [sp, #76]
.LVL539:
.LBE6849:
.LBE6857:
.LBE6862:
.LBE6867:
.LBE6872:
.LBE6898:
.LBB6899:
.LBB6892:
.LBB6888:
.LBB6885:
.LBB6882:
	.loc 15 135 0
	str	r3, [sp, #12]
.LBE6882:
.LBE6885:
.LBE6888:
.LBE6892:
.LBE6899:
	.loc 23 191 0
	bl	_ZmlRK11btMatrix3x3RK9btVector3
.LVL540:
.LBB6900:
.LBB6901:
.LBB6902:
	.loc 23 60 0
	add	r1, sp, #32
	mov	r0, r4
	bl	_ZN11btMatrix3x3C1ERKS_
	mov	r3, r4
	add	r3, r3, #48
	ldmia	r5!, {r0, r1, r2}
	stmia	r3!, {r0, r1, r2}
.LVL541:
	ldr	r2, [r5]
.LBE6902:
.LBE6901:
.LBE6900:
.LBE6907:
	.loc 23 192 0
	add	sp, sp, #84
.LVL542:
	mov	r0, r4
.LBB6908:
.LBB6905:
.LBB6904:
.LBB6903:
	.loc 23 60 0
	str	r2, [r3]
.LBE6903:
.LBE6904:
.LBE6905:
.LBE6908:
	.loc 23 192 0
	@ sp needed for prologue
.LVL543:
.LVL544:
	pop	{r4, r5, pc}
	.cfi_endproc
.LFE334:
	.fnend
	.size	_ZNK11btTransform7inverseEv, .-_ZNK11btTransform7inverseEv
	.section	.text._ZNK11btTransform8invXformERK9btVector3,"axG",%progbits,_ZNK11btTransform8invXformERK9btVector3,comdat
	.align	1
	.weak	_ZNK11btTransform8invXformERK9btVector3
	.code	16
	.thumb_func
	.type	_ZNK11btTransform8invXformERK9btVector3, %function
_ZNK11btTransform8invXformERK9btVector3:
	.fnstart
.LFB336:
	.loc 23 224 0
	.cfi_startproc
	.save	{r4, r5, lr}
	push	{r4, r5, lr}
.LCFI81:
	.cfi_def_cfa_offset 12
	.cfi_offset 4, -12
	.cfi_offset 5, -8
	.cfi_offset 14, -4
.LVL545:
.LBB6909:
	.loc 23 225 0
	mov	r3, r1
.LBE6909:
	.loc 23 224 0
	.pad #68
	sub	sp, sp, #68
.LCFI82:
	.cfi_def_cfa_offset 80
.LBB6950:
	.loc 23 225 0
	add	r3, r3, #48
.LBE6950:
	.loc 23 224 0
	mov	r4, r1
	mov	r5, r0
.LBB6951:
	.loc 23 225 0
	mov	r1, r2
.LVL546:
	mov	r0, sp
.LVL547:
	mov	r2, r3
.LVL548:
	bl	_ZmiRK9btVector3S1_
.LVL549:
.LBB6910:
.LBB6911:
.LBB6912:
.LBB6913:
.LBB6914:
.LBB6915:
	.loc 15 632 0
	ldr	r2, [r4, #4]
.LBE6915:
.LBE6914:
.LBB6920:
.LBB6921:
	ldr	r3, [r4]
.LBE6921:
.LBE6920:
.LBE6913:
.LBE6912:
.LBE6911:
.LBE6910:
	.loc 23 226 0
	mov	r0, r5
.LBB6948:
.LBB6946:
.LBB6944:
.LBB6942:
.LBB6926:
.LBB6916:
	.loc 15 632 0
	str	r2, [sp, #32]
	.loc 15 633 0
	ldr	r2, [r4, #20]
.LBE6916:
.LBE6926:
.LBB6927:
.LBB6922:
	.loc 15 632 0
	str	r3, [sp, #16]
	.loc 15 633 0
	ldr	r3, [r4, #16]
.LBE6922:
.LBE6927:
.LBB6928:
.LBB6917:
	str	r2, [sp, #36]
	.loc 15 634 0
	ldr	r2, [r4, #36]
.LBE6917:
.LBE6928:
.LBB6929:
.LBB6923:
	.loc 15 633 0
	str	r3, [sp, #20]
	.loc 15 634 0
	ldr	r3, [r4, #32]
.LBE6923:
.LBE6929:
.LBB6930:
.LBB6918:
	str	r2, [sp, #40]
.LBE6918:
.LBE6930:
.LBB6931:
.LBB6932:
	.loc 15 632 0
	ldr	r2, [r4, #8]
.LBE6932:
.LBE6931:
.LBB6936:
.LBB6924:
	.loc 15 634 0
	str	r3, [sp, #24]
.LBE6924:
.LBE6936:
.LBE6942:
.LBE6944:
.LBE6946:
.LBE6948:
	.loc 23 226 0
	add	r1, sp, #16
.LBB6949:
.LBB6947:
.LBB6945:
.LBB6943:
.LBB6937:
.LBB6933:
	.loc 15 632 0
	str	r2, [sp, #48]
	.loc 15 633 0
	ldr	r2, [r4, #24]
.LBE6933:
.LBE6937:
.LBB6938:
.LBB6925:
	.loc 15 635 0
	mov	r3, #0
	str	r3, [sp, #28]
.LVL550:
.LBE6925:
.LBE6938:
.LBB6939:
.LBB6934:
	.loc 15 633 0
	str	r2, [sp, #52]
	.loc 15 634 0
	ldr	r2, [r4, #40]
.LBE6934:
.LBE6939:
.LBB6940:
.LBB6919:
	.loc 15 635 0
	str	r3, [sp, #44]
.LVL551:
.LBE6919:
.LBE6940:
.LBB6941:
.LBB6935:
	str	r3, [sp, #60]
	.loc 15 634 0
	str	r2, [sp, #56]
.LBE6935:
.LBE6941:
.LBE6943:
.LBE6945:
.LBE6947:
.LBE6949:
	.loc 23 226 0
	mov	r2, sp
	bl	_ZmlRK11btMatrix3x3RK9btVector3
.LBE6951:
	.loc 23 227 0
	add	sp, sp, #68
	mov	r0, r5
	@ sp needed for prologue
.LVL552:
.LVL553:
	pop	{r4, r5, pc}
	.cfi_endproc
.LFE336:
	.fnend
	.size	_ZNK11btTransform8invXformERK9btVector3, .-_ZNK11btTransform8invXformERK9btVector3
	.section	.text._ZNK11btTransform12inverseTimesERKS_,"axG",%progbits,_ZNK11btTransform12inverseTimesERKS_,comdat
	.align	1
	.weak	_ZNK11btTransform12inverseTimesERKS_
	.code	16
	.thumb_func
	.type	_ZNK11btTransform12inverseTimesERKS_, %function
_ZNK11btTransform12inverseTimesERKS_:
	.fnstart
.LFB337:
	.loc 23 231 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI83:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL554:
	mov	r5, r1
	.pad #92
	sub	sp, sp, #92
.LCFI84:
	.cfi_def_cfa_offset 112
	.loc 23 231 0
	mov	r4, r2
.LBB6952:
	.loc 23 232 0
	mov	r1, r2
.LVL555:
	mov	r2, r5
.LVL556:
.LBE6952:
	.loc 23 231 0
	mov	r6, r0
.LBB6980:
	.loc 23 232 0
	add	r1, r1, #48
.LVL557:
	add	r0, sp, #8
.LVL558:
	add	r2, r2, #48
	bl	_ZmiRK9btVector3S1_
	.loc 23 234 0
	mov	r2, r4
	mov	r1, r5
	add	r0, sp, #40
	bl	_ZNK11btMatrix3x314transposeTimesERKS_
.LVL559:
.LBB6953:
.LBB6954:
	.loc 21 1192 0
	mov	r0, r5
	add	r1, sp, #8
.LVL560:
	bl	_ZNK11btMatrix3x35tdotxERK9btVector3
.LVL561:
	add	r1, sp, #8
.LVL562:
	add	r7, r0, #0
	mov	r0, r5
	bl	_ZNK11btMatrix3x35tdotyERK9btVector3
.LVL563:
	add	r1, sp, #8
.LVL564:
	str	r0, [sp, #4]
	mov	r0, r5
	bl	_ZNK11btMatrix3x35tdotzERK9btVector3
.LVL565:
.LBB6955:
.LBB6956:
.LBB6957:
	.loc 15 133 0
	ldr	r1, [sp, #4]
	.loc 15 134 0
	str	r0, [sp, #32]
	.loc 15 135 0
	mov	r3, #0
	.loc 15 133 0
	str	r1, [sp, #28]
.LBE6957:
.LBE6956:
.LBE6955:
.LBE6954:
.LBE6953:
.LBB6966:
.LBB6967:
.LBB6968:
	.loc 23 60 0
	mov	r0, r6
	add	r1, sp, #40
.LBE6968:
.LBE6967:
.LBE6966:
.LBB6975:
.LBB6964:
.LBB6962:
.LBB6960:
.LBB6958:
	.loc 15 132 0
	str	r7, [sp, #24]
	.loc 15 135 0
	str	r3, [sp, #36]
.LVL566:
.LBE6958:
.LBE6960:
.LBE6962:
.LBE6964:
.LBE6975:
.LBB6976:
.LBB6972:
.LBB6969:
	.loc 23 60 0
	bl	_ZN11btMatrix3x3C1ERKS_
.LVL567:
	mov	r3, r6
.LBE6969:
.LBE6972:
.LBE6976:
.LBB6977:
.LBB6965:
.LBB6963:
.LBB6961:
.LBB6959:
	.loc 15 132 0
	add	r4, sp, #24
.LVL568:
.LBE6959:
.LBE6961:
.LBE6963:
.LBE6965:
.LBE6977:
.LBB6978:
.LBB6973:
.LBB6970:
	.loc 23 60 0
	add	r3, r3, #48
	ldmia	r4!, {r0, r1, r2}
	stmia	r3!, {r0, r1, r2}
	ldr	r2, [r4]
.LBE6970:
.LBE6973:
.LBE6978:
.LBE6980:
	.loc 23 235 0
	add	sp, sp, #92
	mov	r0, r6
.LBB6981:
.LBB6979:
.LBB6974:
.LBB6971:
	.loc 23 60 0
	str	r2, [r3]
.LBE6971:
.LBE6974:
.LBE6979:
.LBE6981:
	.loc 23 235 0
	@ sp needed for prologue
.LVL569:
.LVL570:
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE337:
	.fnend
	.size	_ZNK11btTransform12inverseTimesERKS_, .-_ZNK11btTransform12inverseTimesERKS_
	.section	.text._ZNK11btTransformmlERKS_,"axG",%progbits,_ZNK11btTransformmlERKS_,comdat
	.align	1
	.weak	_ZNK11btTransformmlERKS_
	.code	16
	.thumb_func
	.type	_ZNK11btTransformmlERKS_, %function
_ZNK11btTransformmlERKS_:
	.fnstart
.LFB338:
	.loc 23 239 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI85:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL571:
	.pad #68
	sub	sp, sp, #68
.LCFI86:
	.cfi_def_cfa_offset 88
	.loc 23 239 0
	mov	r5, r0
	mov	r4, r2
	.loc 23 241 0
	add	r0, sp, #16
.LVL572:
	.loc 23 239 0
	mov	r6, r1
	.loc 23 241 0
	bl	_ZmlRK11btMatrix3x3S1_
.LVL573:
	mov	r2, r4
	add	r2, r2, #48
	mov	r1, r6
	mov	r0, sp
	bl	_ZNK11btTransformclERK9btVector3
.LVL574:
.LBB6982:
.LBB6983:
.LBB6984:
	.loc 23 60 0
	add	r1, sp, #16
.LVL575:
	mov	r0, r5
	bl	_ZN11btMatrix3x3C1ERKS_
.LVL576:
	mov	r3, r5
.LBE6984:
.LBE6983:
.LBE6982:
	.loc 23 241 0
	mov	r7, sp
.LBB6989:
.LBB6987:
.LBB6985:
	.loc 23 60 0
	add	r3, r3, #48
	ldmia	r7!, {r0, r1, r2}
	stmia	r3!, {r0, r1, r2}
	ldr	r2, [r7]
.LBE6985:
.LBE6987:
.LBE6989:
	.loc 23 242 0
	add	sp, sp, #68
.LVL577:
	mov	r0, r5
.LBB6990:
.LBB6988:
.LBB6986:
	.loc 23 60 0
	str	r2, [r3]
.LBE6986:
.LBE6988:
.LBE6990:
	.loc 23 242 0
	@ sp needed for prologue
.LVL578:
.LVL579:
.LVL580:
.LVL581:
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE338:
	.fnend
	.size	_ZNK11btTransformmlERKS_, .-_ZNK11btTransformmlERKS_
	.section	.text._ZN15btTransformUtil22calculateDiffAxisAngleERK11btTransformS2_R9btVector3Rf,"axG",%progbits,_ZN15btTransformUtil22calculateDiffAxisAngleERK11btTransformS2_R9btVector3Rf,comdat
	.align	1
	.weak	_ZN15btTransformUtil22calculateDiffAxisAngleERK11btTransformS2_R9btVector3Rf
	.code	16
	.thumb_func
	.type	_ZN15btTransformUtil22calculateDiffAxisAngleERK11btTransformS2_R9btVector3Rf, %function
_ZN15btTransformUtil22calculateDiffAxisAngleERK11btTransformS2_R9btVector3Rf:
	.fnstart
.LFB470:
	.file 24 "jni/../../../bullet4droid/jni/src/LinearMath/btTransformUtil.h"
	.loc 24 121 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI87:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL582:
	.pad #124
	sub	sp, sp, #124
.LCFI88:
	.cfi_def_cfa_offset 144
	.loc 24 121 0
	mov	r5, r0
	mov	r6, r1
.LVL583:
.LBB6991:
	.loc 24 123 0
	add	r0, sp, #72
.LVL584:
	mov	r1, r5
.LVL585:
.LBE6991:
	.loc 24 121 0
	str	r3, [sp, #4]
	mov	r4, r2
.LBB7017:
	.loc 24 123 0
	bl	_ZNK11btMatrix3x37inverseEv
.LVL586:
	add	r2, sp, #72
	add	r0, sp, #24
	mov	r1, r6
	bl	_ZmlRK11btMatrix3x3S1_
.LVL587:
	.loc 24 125 0
	add	r1, sp, #8
	add	r0, sp, #24
	bl	_ZNK11btMatrix3x311getRotationER12btQuaternion
	.loc 24 128 0
	add	r0, sp, #8
	bl	_ZN12btQuaternion9normalizeEv
.LVL588:
.LBB6992:
.LBB6993:
	.loc 20 404 0
	ldr	r5, [sp, #20]
.LVL589:
.LBB6994:
.LBB6995:
	.loc 16 390 0
	ldr	r1, .L407
	add	r0, r5, #0
	bl	__aeabi_fcmplt
.LVL590:
	cmp	r0, #0
	beq	.L397
	.loc 16 391 0
	ldr	r5, .L407
.LVL591:
.L397:
	.loc 16 392 0
	mov	r1, #254
	add	r0, r5, #0
	lsl	r1, r1, #22
	bl	__aeabi_fcmpgt
	mov	r7, #254
	lsl	r7, r7, #22
	cmp	r0, #0
	beq	.L398
	.loc 16 393 0
	add	r5, r7, #0
.LVL592:
.L398:
	.loc 16 394 0
	add	r0, r5, #0
	bl	acosf
	add	r1, r0, #0
.LVL593:
.LBE6995:
.LBE6994:
	.loc 20 404 0
	bl	__aeabi_fadd
.LVL594:
.LBE6993:
.LBE6992:
	.loc 24 130 0
	ldr	r3, [sp, #4]
.LBB6996:
.LBB6997:
.LBB6998:
	.loc 15 133 0
	ldr	r2, [sp, #12]
	.loc 24 131 0
	ldr	r1, [sp, #8]
.LBE6998:
.LBE6997:
.LBE6996:
	.loc 24 130 0
	str	r0, [r3]
.LVL595:
.LBB7003:
.LBB7001:
.LBB6999:
	.loc 15 134 0
	ldr	r3, [sp, #16]
	.loc 24 131 0
	mov	r5, #0
.LVL596:
	str	r1, [r4]
	str	r2, [r4, #4]
.LBE6999:
.LBE7001:
.LBE7003:
.LBB7004:
.LBB7005:
	.loc 15 258 0
	mov	r1, r4
.LBE7005:
.LBE7004:
.LBB7008:
.LBB7002:
.LBB7000:
	.loc 24 131 0
	str	r3, [r4, #8]
	str	r5, [r4, #12]
.LVL597:
.LBE7000:
.LBE7002:
.LBE7008:
.LBB7009:
.LBB7006:
	.loc 15 258 0
	mov	r0, r4
	bl	_ZNK9btVector33dotERKS_
.LBE7006:
.LBE7009:
	.loc 24 135 0
	mov	r1, #162
	lsl	r1, r1, #22
.LBB7010:
.LBB7007:
	.loc 15 258 0
	add	r6, r0, #0
.LVL598:
.LBE7007:
.LBE7010:
	.loc 24 135 0
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L406
.LVL599:
	.loc 24 136 0
	str	r7, [r4]
	str	r5, [r4, #4]
	str	r5, [r4, #8]
	b	.L394
.LVL600:
.L406:
.LBB7011:
.LBB7012:
	.loc 16 382 0
	add	r0, r6, #0
	bl	sqrtf
	add	r1, r0, #0
.LVL601:
.LBE7012:
.LBE7011:
.LBB7013:
.LBB7014:
	.loc 15 228 0
	mov	r0, #254
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
	add	r5, r0, #0
.LVL602:
.LBB7015:
.LBB7016:
	.loc 15 205 0
	add	r1, r5, #0
	ldr	r0, [r4]
	bl	__aeabi_fmul
	.loc 15 206 0
	add	r1, r5, #0
	.loc 15 205 0
	str	r0, [r4]
	.loc 15 206 0
	ldr	r0, [r4, #4]
	bl	__aeabi_fmul
	.loc 15 207 0
	add	r1, r5, #0
	.loc 15 206 0
	str	r0, [r4, #4]
	.loc 15 207 0
	ldr	r0, [r4, #8]
	bl	__aeabi_fmul
	str	r0, [r4, #8]
.LVL603:
.L394:
.LBE7016:
.LBE7015:
.LBE7014:
.LBE7013:
.LBE7017:
	.loc 24 139 0
	add	sp, sp, #124
	@ sp needed for prologue
.LVL604:
	pop	{r4, r5, r6, r7, pc}
.L408:
	.align	2
.L407:
	.word	-1082130432
	.cfi_endproc
.LFE470:
	.fnend
	.size	_ZN15btTransformUtil22calculateDiffAxisAngleERK11btTransformS2_R9btVector3Rf, .-_ZN15btTransformUtil22calculateDiffAxisAngleERK11btTransformS2_R9btVector3Rf
	.section	.text._ZN15btTransformUtil17calculateVelocityERK11btTransformS2_fR9btVector3S4_,"axG",%progbits,_ZN15btTransformUtil17calculateVelocityERK11btTransformS2_fR9btVector3S4_,comdat
	.align	1
	.weak	_ZN15btTransformUtil17calculateVelocityERK11btTransformS2_fR9btVector3S4_
	.code	16
	.thumb_func
	.type	_ZN15btTransformUtil17calculateVelocityERK11btTransformS2_fR9btVector3S4_, %function
_ZN15btTransformUtil17calculateVelocityERK11btTransformS2_fR9btVector3S4_:
	.fnstart
.LFB469:
	.loc 24 112 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI89:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL605:
	.pad #60
	sub	sp, sp, #60
.LCFI90:
	.cfi_def_cfa_offset 80
.LVL606:
	.loc 24 112 0
	add	r4, r2, #0
.LBB7018:
	.loc 24 114 0
	mov	r2, r0
.LVL607:
	add	r2, r2, #48
.LBE7018:
	.loc 24 112 0
	mov	r7, r0
	str	r1, [sp, #4]
.LBB7046:
	.loc 24 114 0
	add	r0, sp, #24
.LVL608:
	add	r1, r1, #48
.LVL609:
.LBE7046:
	.loc 24 112 0
	mov	r5, r3
	ldr	r6, [sp, #80]
.LBB7047:
	.loc 24 114 0
	bl	_ZmiRK9btVector3S1_
.LVL610:
.LBB7019:
.LBB7020:
	.loc 15 842 0
	mov	r0, #254
	add	r1, r4, #0
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
.LBB7021:
.LBB7022:
	.loc 15 818 0
	ldr	r1, [sp, #24]
.LBE7022:
.LBE7021:
	.loc 15 842 0
	add	r4, r0, #0
.LVL611:
.LBB7026:
.LBB7023:
	.loc 15 818 0
	bl	__aeabi_fmul
	ldr	r1, [sp, #28]
	str	r0, [sp, #8]
	add	r0, r4, #0
	bl	__aeabi_fmul
	ldr	r1, [sp, #32]
	str	r0, [sp, #12]
	add	r0, r4, #0
	bl	__aeabi_fmul
.LVL612:
	.loc 24 114 0
	ldr	r3, [sp, #8]
.LBE7023:
.LBE7026:
.LBE7020:
.LBE7019:
	.loc 24 117 0
	add	r2, sp, #40
.LBB7031:
.LBB7029:
.LBB7027:
.LBB7024:
	.loc 24 114 0
	str	r0, [r5, #8]
	str	r3, [r5]
	ldr	r3, [sp, #12]
.LBE7024:
.LBE7027:
.LBE7029:
.LBE7031:
	.loc 24 117 0
	mov	r0, r7
	ldr	r1, [sp, #4]
.LBB7032:
.LBB7030:
.LBB7028:
.LBB7025:
	.loc 24 114 0
	str	r3, [r5, #4]
	mov	r3, #0
	str	r3, [r5, #12]
.LVL613:
.LBE7025:
.LBE7028:
.LBE7030:
.LBE7032:
	.loc 24 117 0
	add	r3, sp, #20
	bl	_ZN15btTransformUtil22calculateDiffAxisAngleERK11btTransformS2_R9btVector3Rf
.LVL614:
	.loc 8 1535 0
	ldr	r5, [sp, #20]
.LVL615:
.LBB7033:
.LBB7034:
	.loc 15 818 0
	ldr	r1, [sp, #40]
	add	r0, r5, #0
	bl	__aeabi_fmul
	ldr	r1, [sp, #44]
	add	r7, r0, #0
.LVL616:
	add	r0, r5, #0
	bl	__aeabi_fmul
	ldr	r1, [sp, #48]
	str	r0, [sp, #4]
	add	r0, r5, #0
	bl	__aeabi_fmul
.LBE7034:
.LBE7033:
.LBB7036:
.LBB7037:
.LBB7038:
	add	r1, r4, #0
.LBE7038:
.LBE7037:
.LBE7036:
.LBB7043:
.LBB7035:
	str	r0, [sp, #8]
.LVL617:
.LBE7035:
.LBE7043:
.LBB7044:
.LBB7041:
.LBB7039:
	add	r0, r7, #0
	bl	__aeabi_fmul
	add	r1, r4, #0
	add	r5, r0, #0
	ldr	r0, [sp, #4]
	bl	__aeabi_fmul
	add	r1, r4, #0
	add	r7, r0, #0
	ldr	r0, [sp, #8]
	bl	__aeabi_fmul
.LVL618:
	.loc 24 118 0
	mov	r3, #0
.LBE7039:
.LBE7041:
.LBE7044:
.LBE7047:
	.loc 24 119 0
	add	sp, sp, #60
.LBB7048:
.LBB7045:
.LBB7042:
.LBB7040:
	.loc 24 118 0
	str	r5, [r6]
	str	r7, [r6, #4]
	str	r0, [r6, #8]
	str	r3, [r6, #12]
.LBE7040:
.LBE7042:
.LBE7045:
.LBE7048:
	.loc 24 119 0
	@ sp needed for prologue
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE469:
	.fnend
	.size	_ZN15btTransformUtil17calculateVelocityERK11btTransformS2_fR9btVector3S4_, .-_ZN15btTransformUtil17calculateVelocityERK11btTransformS2_fR9btVector3S4_
	.section	.text._ZN15btManifoldPointC2ERK9btVector3S2_S2_f,"axG",%progbits,_ZN15btManifoldPointC5ERK9btVector3S2_S2_f,comdat
	.align	1
	.weak	_ZN15btManifoldPointC2ERK9btVector3S2_S2_f
	.code	16
	.thumb_func
	.type	_ZN15btManifoldPointC2ERK9btVector3S2_S2_f, %function
_ZN15btManifoldPointC2ERK9btVector3S2_S2_f:
	.fnstart
.LFB481:
	.loc 19 59 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI91:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL619:
.LBB7049:
	.loc 19 78 0
	mov	r4, r0
	ldmia	r1!, {r5, r6, r7}
	stmia	r4!, {r5, r6, r7}
.LVL620:
	ldr	r1, [r1]
.LVL621:
.LBE7049:
	.loc 19 81 0
	@ sp needed for prologue
.LBB7050:
	.loc 19 78 0
	str	r1, [r4]
	mov	r1, r0
	add	r1, r1, #16
	ldmia	r2!, {r4, r5, r6}
	stmia	r1!, {r4, r5, r6}
.LVL622:
	ldr	r2, [r2]
.LVL623:
	str	r2, [r1]
.LVL624:
	mov	r2, r0
	add	r2, r2, #64
	ldmia	r3!, {r1, r4, r7}
	stmia	r2!, {r1, r4, r7}
.LVL625:
	ldr	r3, [r3]
.LVL626:
	mov	r1, r0
	add	r1, r1, #116
	str	r3, [r2]
	ldr	r3, [sp, #20]
	mov	r2, #0
	str	r2, [r0, #112]
	str	r3, [r0, #80]
	mov	r3, #0
	str	r3, [r0, #84]
	str	r3, [r0, #88]
	str	r3, [r0, #92]
	strb	r2, [r1]
	add	r1, r0, #4
	str	r3, [r0, #120]
	str	r3, [r0, #124]
	str	r3, [r1, #124]
	add	r1, r1, #4
	str	r3, [r1, #124]
	add	r1, r1, #128
	str	r3, [r1]
	str	r3, [r1, #4]
	str	r3, [r1, #8]
	mov	r3, r0
	add	r3, r3, #148
	str	r2, [r3]
.LVL627:
.LBE7050:
	.loc 19 81 0
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE481:
	.fnend
	.size	_ZN15btManifoldPointC2ERK9btVector3S2_S2_f, .-_ZN15btManifoldPointC2ERK9btVector3S2_S2_f
	.section	.text._ZN23btBridgedManifoldResult15addContactPointERK9btVector3S2_f,"axG",%progbits,_ZN23btBridgedManifoldResult15addContactPointERK9btVector3S2_f,comdat
	.align	1
	.weak	_ZN23btBridgedManifoldResult15addContactPointERK9btVector3S2_f
	.code	16
	.thumb_func
	.type	_ZN23btBridgedManifoldResult15addContactPointERK9btVector3S2_f, %function
_ZN23btBridgedManifoldResult15addContactPointERK9btVector3S2_f:
	.fnstart
.LFB1616:
	.loc 8 1065 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI92:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL628:
	.pad #300
	sub	sp, sp, #300
.LCFI93:
	.cfi_def_cfa_offset 320
.LBB7051:
	.loc 8 1067 0
	ldr	r5, [r0, #8]
.LVL629:
.LBE7051:
	.loc 8 1065 0
	str	r2, [sp, #16]
.LBB7079:
.LBB7052:
.LBB7053:
	.loc 18 94 0
	ldr	r2, [r0, #4]
.LVL630:
.LBE7053:
.LBE7052:
.LBE7079:
	.loc 8 1065 0
	add	r7, r3, #0
.LBB7080:
.LBB7055:
.LBB7054:
	.loc 18 94 0
	mov	r3, #185
.LVL631:
	lsl	r3, r3, #2
.LBE7054:
.LBE7055:
	.loc 8 1067 0
	ldr	r2, [r2, r3]
	ldr	r3, [r5, #8]
.LBE7080:
	.loc 8 1065 0
	mov	r4, r0
	str	r1, [sp, #20]
.LBB7081:
	.loc 8 1067 0
	sub	r3, r2, r3
	mov	r0, r3
.LVL632:
	sub	r3, r0, #1
	sbc	r0, r0, r3
.LBB7056:
.LBB7057:
	.loc 15 818 0
	ldr	r1, [r1, #4]
.LVL633:
.LBE7057:
.LBE7056:
	.loc 8 1067 0
	str	r0, [sp, #24]
.LVL634:
.LBB7070:
.LBB7067:
	.loc 15 818 0
	add	r0, r7, #0
	bl	__aeabi_fmul
.LVL635:
	ldr	r2, [sp, #20]
	add	r6, r0, #0
	add	r0, r7, #0
	ldr	r1, [r2, #8]
	bl	__aeabi_fmul
	ldr	r3, [sp, #20]
	str	r0, [sp, #28]
.LVL636:
	add	r1, r7, #0
	ldr	r0, [r3]
	bl	__aeabi_fmul
.LBB7058:
.LBB7059:
.LBB7060:
	.loc 15 132 0
	str	r0, [sp, #64]
	.loc 15 134 0
	ldr	r0, [sp, #28]
	.loc 15 135 0
	mov	r3, #0
.LBE7060:
.LBE7059:
.LBE7058:
.LBE7067:
.LBE7070:
	.loc 8 1068 0
	ldr	r1, [sp, #16]
.LBB7071:
.LBB7068:
.LBB7065:
.LBB7063:
.LBB7061:
	.loc 15 134 0
	str	r0, [sp, #72]
.LBE7061:
.LBE7063:
.LBE7065:
.LBE7068:
.LBE7071:
	.loc 8 1068 0
	add	r2, sp, #64
	add	r0, sp, #48
.LBB7072:
.LBB7069:
.LBB7066:
.LBB7064:
.LBB7062:
	.loc 15 133 0
	str	r6, [sp, #68]
	.loc 15 135 0
	str	r3, [sp, #76]
.LBE7062:
.LBE7064:
.LBE7066:
.LBE7069:
.LBE7072:
	.loc 8 1068 0
	bl	_ZplRK9btVector3S1_
.LVL637:
	.loc 8 1071 0
	ldr	r2, [sp, #24]
	add	r1, sp, #80
	str	r1, [sp, #28]
	add	r6, sp, #32
	cmp	r2, #0
	beq	.L424
.LVL638:
.LBB7073:
.LBB7074:
	.loc 13 39 0
	ldr	r3, [r4, #12]
.LBE7074:
.LBE7073:
	.loc 8 1073 0
	add	r2, sp, #48
	mov	r0, r6
	ldr	r1, [r3, #8]
	mov	r5, r6
.LVL639:
	add	r1, r1, #4
	bl	_ZNK11btTransform8invXformERK9btVector3
.LVL640:
	ldr	r3, [sp, #28]
	ldmia	r5!, {r0, r1, r2}
	stmia	r3!, {r0, r1, r2}
	ldr	r2, [r5]
	str	r2, [r3]
.LVL641:
	.loc 8 1074 0
	add	r3, sp, #96
	str	r3, [sp, #28]
.LBB7075:
.LBB7076:
	.loc 13 39 0
	ldr	r3, [r4, #8]
	b	.L428
.LVL642:
.L424:
.LBE7076:
.LBE7075:
	.loc 8 1077 0
	ldr	r1, [r5, #8]
	add	r2, sp, #48
	mov	r0, r6
	add	r1, r1, #4
	bl	_ZNK11btTransform8invXformERK9btVector3
.LVL643:
	ldr	r3, [sp, #28]
	mov	r5, r6
.LVL644:
	ldmia	r5!, {r0, r1, r2}
	stmia	r3!, {r0, r1, r2}
	ldr	r2, [r5]
	str	r2, [r3]
.LVL645:
	.loc 8 1078 0
	add	r3, sp, #96
	str	r3, [sp, #28]
.LBB7077:
.LBB7078:
	.loc 13 39 0
	ldr	r3, [r4, #12]
.LVL646:
.L428:
.LBE7078:
.LBE7077:
	.loc 8 1078 0
	ldr	r1, [r3, #8]
	mov	r0, r6
	ldr	r2, [sp, #16]
	add	r1, r1, #4
	bl	_ZNK11btTransform8invXformERK9btVector3
	ldr	r3, [sp, #28]
	ldmia	r6!, {r0, r1, r2}
	stmia	r3!, {r0, r1, r2}
	ldr	r2, [r5]
	.loc 8 1081 0
	add	r1, sp, #80
	add	r0, sp, #112
	.loc 8 1078 0
	str	r2, [r3]
	.loc 8 1081 0
	ldr	r3, [sp, #20]
	add	r2, sp, #96
	str	r7, [sp]
	bl	_ZN15btManifoldPointC1ERK9btVector3S2_S2_f
	.loc 8 1082 0
	add	r1, sp, #48
	mov	r2, #16
	add	r0, sp, #160
	bl	memcpy
	.loc 8 1083 0
	ldr	r2, [sp, #16]
	add	r3, sp, #144
	ldmia	r2!, {r0, r5, r7}
	stmia	r3!, {r0, r5, r7}
.LVL647:
	ldr	r2, [r2]
	str	r2, [r3]
	.loc 8 1086 0
	ldr	r7, [sp, #24]
	ldr	r1, [r4, #8]
	ldr	r3, [r4, #12]
	ldr	r5, [r4, #20]
	ldr	r6, [r4, #16]
	ldr	r2, [r4, #28]
	ldr	r0, [r4, #24]
	cmp	r7, #0
	beq	.L426
	.loc 8 1090 0
	str	r2, [sp, #216]
	.loc 8 1088 0
	str	r5, [sp, #208]
	.loc 8 1089 0
	str	r6, [sp, #212]
	.loc 8 1091 0
	str	r0, [sp, #220]
	.loc 8 1101 0 discriminator 1
	mov	r2, r3
.LVL648:
	b	.L427
.LVL649:
.L426:
	.loc 8 1097 0
	str	r2, [sp, #220]
	.loc 8 1094 0
	str	r6, [sp, #208]
	.loc 8 1101 0 discriminator 2
	mov	r2, r1
.LVL650:
	.loc 8 1095 0
	str	r5, [sp, #212]
	.loc 8 1096 0
	str	r0, [sp, #216]
	.loc 8 1102 0 discriminator 2
	mov	r1, r3
.LVL651:
.L427:
	.loc 8 1103 0
	ldr	r0, [r4, #32]
	ldr	r5, [sp, #216]
	ldr	r3, [sp, #208]
	ldr	r4, [r0]
.LVL652:
	str	r1, [sp, #4]
	ldr	r1, [sp, #212]
.LVL653:
	str	r5, [sp]
	str	r1, [sp, #8]
	ldr	r1, [sp, #220]
	str	r1, [sp, #12]
	ldr	r4, [r4, #12]
	add	r1, sp, #112
	blx	r4
.LVL654:
.LBE7081:
	.loc 8 1105 0
	add	sp, sp, #300
	@ sp needed for prologue
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE1616:
	.fnend
	.size	_ZN23btBridgedManifoldResult15addContactPointERK9btVector3S2_f, .-_ZN23btBridgedManifoldResult15addContactPointERK9btVector3S2_f
	.section	.text._Z10btRayAabb2RK9btVector3S1_PKjPS0_Rfff,"axG",%progbits,_Z10btRayAabb2RK9btVector3S1_PKjPS0_Rfff,comdat
	.align	1
	.weak	_Z10btRayAabb2RK9btVector3S1_PKjPS0_Rfff
	.code	16
	.thumb_func
	.type	_Z10btRayAabb2RK9btVector3S1_PKjPS0_Rfff, %function
_Z10btRayAabb2RK9btVector3S1_PKjPS0_Rfff:
	.fnstart
.LFB828:
	.file 25 "jni/../../../bullet4droid/jni/src/LinearMath/btAabbUtil2.h"
	.loc 25 97 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI94:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL655:
	.pad #44
	sub	sp, sp, #44
.LCFI95:
	.cfi_def_cfa_offset 64
	.loc 25 97 0
	mov	r7, r3
.LVL656:
	str	r0, [sp, #4]
.LBB7082:
	.loc 25 99 0
	ldr	r3, [r2]
.LVL657:
.LBE7082:
	.loc 25 97 0
	mov	r4, r2
.LBB7083:
	.loc 25 99 0
	ldr	r2, [sp, #4]
.LVL658:
	lsl	r3, r3, #4
	ldr	r0, [r3, r7]
.LVL659:
.LBE7083:
	.loc 25 97 0
	str	r1, [sp, #20]
.LBB7084:
	.loc 25 99 0
	ldr	r1, [r2]
.LVL660:
	bl	__aeabi_fsub
.LVL661:
	ldr	r3, [sp, #20]
	ldr	r1, [r3]
	bl	__aeabi_fmul
	ldr	r2, [sp, #64]
	add	r5, r0, #0
	str	r0, [r2]
.LVL662:
	.loc 25 100 0
	ldr	r3, [r4]
	ldr	r2, [sp, #20]
	lsl	r3, r3, #4
	sub	r3, r7, r3
	ldr	r6, [r3, #16]
.LVL663:
	ldr	r3, [sp, #4]
	ldr	r2, [r2]
	ldr	r3, [r3]
	str	r2, [sp, #32]
	str	r3, [sp, #28]
.LVL664:
	.loc 25 101 0
	ldr	r3, [r4, #4]
.LVL665:
	lsl	r2, r3, #4
	add	r2, r7, r2
	ldr	r2, [r2, #4]
	.loc 25 102 0
	lsl	r3, r3, #4
	sub	r3, r7, r3
	.loc 25 101 0
	str	r2, [sp, #36]
.LVL666:
	ldr	r2, [sp, #4]
	.loc 25 102 0
	ldr	r0, [r3, #20]
	.loc 25 101 0
	ldr	r2, [r2, #4]
	str	r2, [sp, #8]
.LVL667:
	ldr	r2, [sp, #20]
	.loc 25 102 0
	ldr	r1, [sp, #8]
	.loc 25 101 0
	ldr	r2, [r2, #4]
	str	r2, [sp, #24]
.LVL668:
	.loc 25 102 0
	bl	__aeabi_fsub
.LVL669:
	ldr	r1, [sp, #24]
	bl	__aeabi_fmul
	str	r0, [sp, #12]
.LVL670:
	.loc 25 104 0
	ldr	r1, [sp, #12]
	add	r0, r5, #0
.LVL671:
	bl	__aeabi_fcmpgt
.LVL672:
	.loc 25 105 0
	mov	r3, #0
	str	r3, [sp, #16]
	.loc 25 104 0
	cmp	r0, r3
	bne	.L430
	.loc 25 100 0
	add	r0, r6, #0
	ldr	r1, [sp, #28]
	bl	__aeabi_fsub
	ldr	r1, [sp, #32]
	bl	__aeabi_fmul
	.loc 25 101 0
	ldr	r1, [sp, #8]
	.loc 25 100 0
	add	r6, r0, #0
.LVL673:
	.loc 25 101 0
	ldr	r0, [sp, #36]
	bl	__aeabi_fsub
	ldr	r1, [sp, #24]
	bl	__aeabi_fmul
	.loc 25 104 0 discriminator 1
	add	r1, r6, #0
	.loc 25 101 0
	str	r0, [sp, #8]
	.loc 25 104 0 discriminator 1
	bl	__aeabi_fcmpgt
	cmp	r0, #0
	bne	.L430
	.loc 25 107 0
	ldr	r0, [sp, #8]
	add	r1, r5, #0
	bl	__aeabi_fcmpgt
	cmp	r0, #0
	beq	.L431
	.loc 25 108 0
	ldr	r5, [sp, #8]
.LVL674:
.L431:
	.loc 25 107 0
	ldr	r2, [sp, #64]
	.loc 25 110 0
	ldr	r0, [sp, #12]
	add	r1, r6, #0
	.loc 25 107 0
	str	r5, [r2]
	.loc 25 110 0
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L433
	.loc 25 111 0
	ldr	r6, [sp, #12]
.L433:
.LVL675:
	.loc 25 113 0
	ldr	r3, [r4, #8]
.LVL676:
	lsl	r2, r3, #4
	add	r2, r7, r2
	ldr	r2, [r2, #8]
	.loc 25 114 0
	lsl	r3, r3, #4
	sub	r7, r7, r3
.LVL677:
	.loc 25 113 0
	str	r2, [sp, #12]
.LVL678:
	ldr	r2, [sp, #4]
	.loc 25 114 0
	ldr	r0, [r7, #24]
	.loc 25 113 0
	ldr	r2, [r2, #8]
	str	r2, [sp, #4]
.LVL679:
	ldr	r2, [sp, #20]
	.loc 25 114 0
	ldr	r1, [sp, #4]
	.loc 25 113 0
	ldr	r4, [r2, #8]
.LVL680:
	.loc 25 114 0
	bl	__aeabi_fsub
.LVL681:
	add	r1, r4, #0
	bl	__aeabi_fmul
	add	r7, r0, #0
.LVL682:
	.loc 25 116 0
	add	r1, r7, #0
	add	r0, r5, #0
.LVL683:
	bl	__aeabi_fcmpgt
.LVL684:
	.loc 25 117 0
	mov	r3, #0
	str	r3, [sp, #16]
	.loc 25 116 0
	cmp	r0, r3
	bne	.L430
	.loc 25 113 0
	ldr	r1, [sp, #4]
	ldr	r0, [sp, #12]
	bl	__aeabi_fsub
	add	r1, r4, #0
	bl	__aeabi_fmul
	.loc 25 116 0 discriminator 1
	add	r1, r6, #0
	.loc 25 113 0
	add	r4, r0, #0
.LVL685:
	.loc 25 116 0 discriminator 1
	bl	__aeabi_fcmpgt
	cmp	r0, #0
	bne	.L430
	.loc 25 118 0
	add	r0, r4, #0
	add	r1, r5, #0
	bl	__aeabi_fcmpgt
	cmp	r0, #0
	bne	.L434
	.loc 25 119 0
	add	r4, r5, #0
.L434:
	.loc 25 118 0
	ldr	r2, [sp, #64]
	.loc 25 120 0
	add	r0, r7, #0
	add	r1, r6, #0
	.loc 25 118 0
	str	r4, [r2]
	.loc 25 120 0
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L436
	.loc 25 121 0
	add	r6, r7, #0
.LVL686:
.L436:
	.loc 25 122 0
	add	r0, r4, #0
	ldr	r1, [sp, #72]
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L449
	.loc 25 122 0 is_stmt 0 discriminator 1
	add	r0, r6, #0
	ldr	r1, [sp, #68]
	bl	__aeabi_fcmpgt
	mov	r3, r0
	sub	r0, r3, #1
	sbc	r3, r3, r0
	str	r3, [sp, #16]
	b	.L430
.L449:
	.loc 25 122 0 discriminator 2
	mov	r2, #0
	str	r2, [sp, #16]
.LVL687:
.L430:
.LBE7084:
	.loc 25 123 0 is_stmt 1
	ldr	r0, [sp, #16]
	add	sp, sp, #44
	@ sp needed for prologue
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE828:
	.fnend
	.size	_Z10btRayAabb2RK9btVector3S1_PKjPS0_Rfff, .-_Z10btRayAabb2RK9btVector3S1_PKjPS0_Rfff
	.section	.text._ZNK9btHashPtr7getHashEv,"axG",%progbits,_ZNK9btHashPtr7getHashEv,comdat
	.align	1
	.weak	_ZNK9btHashPtr7getHashEv
	.code	16
	.thumb_func
	.type	_ZNK9btHashPtr7getHashEv, %function
_ZNK9btHashPtr7getHashEv:
	.fnstart
.LFB1005:
	.file 26 "jni/../../../bullet4droid/jni/src/LinearMath/btHashMap.h"
	.loc 26 139 0
	.cfi_startproc
.LVL688:
.LBB7085:
	.loc 26 143 0
	ldr	r2, [r0]
.LVL689:
.LBE7085:
	.loc 26 148 0
	@ sp needed for prologue
.LBB7086:
	.loc 26 146 0
	lsl	r3, r2, #15
	mvn	r3, r3
	add	r3, r2, r3
.LVL690:
	asr	r2, r3, #10
	eor	r3, r2
.LVL691:
	lsl	r2, r3, #3
	add	r3, r3, r2
.LVL692:
	asr	r2, r3, #6
	eor	r3, r2
.LVL693:
	lsl	r2, r3, #11
	mvn	r2, r2
	add	r3, r3, r2
.LVL694:
	asr	r0, r3, #16
.LVL695:
	eor	r0, r3
.LVL696:
.LBE7086:
	.loc 26 148 0
	bx	lr
	.cfi_endproc
.LFE1005:
	.fnend
	.size	_ZNK9btHashPtr7getHashEv, .-_ZNK9btHashPtr7getHashEv
	.section	.text._ZNK10btBoxShape24getHalfExtentsWithMarginEv,"axG",%progbits,_ZNK10btBoxShape24getHalfExtentsWithMarginEv,comdat
	.align	1
	.weak	_ZNK10btBoxShape24getHalfExtentsWithMarginEv
	.code	16
	.thumb_func
	.type	_ZNK10btBoxShape24getHalfExtentsWithMarginEv, %function
_ZNK10btBoxShape24getHalfExtentsWithMarginEv:
	.fnstart
.LFB1353:
	.file 27 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionShapes/btBoxShape.h"
	.loc 27 36 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI96:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL697:
.LBB7087:
	.loc 27 38 0
	mov	r3, r1
	mov	r2, r0
	add	r3, r3, #28
.LBE7087:
	.loc 27 36 0
	mov	r4, r1
	mov	r5, r0
.LBB7094:
	.loc 27 38 0
	ldmia	r3!, {r0, r1, r6}
	stmia	r2!, {r0, r1, r6}
.LVL698:
	ldr	r3, [r3]
.LBE7094:
	.loc 27 36 0
	.pad #20
	sub	sp, sp, #20
.LCFI97:
	.cfi_def_cfa_offset 40
.LBB7095:
	.loc 27 39 0
	mov	r0, r4
	.loc 27 38 0
	str	r3, [r2]
	.loc 27 39 0
	ldr	r3, [r4]
	ldr	r3, [r3, #48]
	blx	r3
	ldr	r3, [r4]
	add	r6, r0, #0
	mov	r0, r4
	ldr	r3, [r3, #48]
	blx	r3
	ldr	r3, [r4]
	add	r7, r0, #0
	mov	r0, r4
	ldr	r3, [r3, #48]
	blx	r3
.LVL699:
.LBB7088:
.LBB7089:
.LBB7090:
	.loc 15 135 0
	mov	r3, #0
	.loc 15 134 0
	str	r0, [sp, #8]
.LBE7090:
.LBE7089:
.LBE7088:
	.loc 27 40 0
	mov	r1, sp
	mov	r0, r5
.LBB7093:
.LBB7092:
.LBB7091:
	.loc 15 132 0
	str	r6, [sp]
	.loc 15 133 0
	str	r7, [sp, #4]
	.loc 15 135 0
	str	r3, [sp, #12]
.LBE7091:
.LBE7092:
.LBE7093:
	.loc 27 40 0
	bl	_ZN9btVector3pLERKS_
.LBE7095:
	.loc 27 42 0
	add	sp, sp, #20
.LVL700:
	mov	r0, r5
	@ sp needed for prologue
.LVL701:
.LVL702:
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE1353:
	.fnend
	.size	_ZNK10btBoxShape24getHalfExtentsWithMarginEv, .-_ZNK10btBoxShape24getHalfExtentsWithMarginEv
	.section	.text._ZNK15btCylinderShape24getHalfExtentsWithMarginEv,"axG",%progbits,_ZNK15btCylinderShape24getHalfExtentsWithMarginEv,comdat
	.align	1
	.weak	_ZNK15btCylinderShape24getHalfExtentsWithMarginEv
	.code	16
	.thumb_func
	.type	_ZNK15btCylinderShape24getHalfExtentsWithMarginEv, %function
_ZNK15btCylinderShape24getHalfExtentsWithMarginEv:
	.fnstart
.LFB1429:
	.file 28 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionShapes/btCylinderShape.h"
	.loc 28 36 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI98:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL703:
.LBB7096:
	.loc 28 38 0
	mov	r3, r1
	mov	r2, r0
	add	r3, r3, #28
.LBE7096:
	.loc 28 36 0
	mov	r4, r1
	mov	r5, r0
.LBB7103:
	.loc 28 38 0
	ldmia	r3!, {r0, r1, r6}
	stmia	r2!, {r0, r1, r6}
.LVL704:
	ldr	r3, [r3]
.LBE7103:
	.loc 28 36 0
	.pad #20
	sub	sp, sp, #20
.LCFI99:
	.cfi_def_cfa_offset 40
.LBB7104:
	.loc 28 39 0
	mov	r0, r4
	.loc 28 38 0
	str	r3, [r2]
	.loc 28 39 0
	ldr	r3, [r4]
	ldr	r3, [r3, #48]
	blx	r3
	ldr	r3, [r4]
	add	r6, r0, #0
	mov	r0, r4
	ldr	r3, [r3, #48]
	blx	r3
	ldr	r3, [r4]
	add	r7, r0, #0
	mov	r0, r4
	ldr	r3, [r3, #48]
	blx	r3
.LVL705:
.LBB7097:
.LBB7098:
.LBB7099:
	.loc 15 135 0
	mov	r3, #0
	.loc 15 134 0
	str	r0, [sp, #8]
.LBE7099:
.LBE7098:
.LBE7097:
	.loc 28 40 0
	mov	r1, sp
	mov	r0, r5
.LBB7102:
.LBB7101:
.LBB7100:
	.loc 15 132 0
	str	r6, [sp]
	.loc 15 133 0
	str	r7, [sp, #4]
	.loc 15 135 0
	str	r3, [sp, #12]
.LBE7100:
.LBE7101:
.LBE7102:
	.loc 28 40 0
	bl	_ZN9btVector3pLERKS_
.LBE7104:
	.loc 28 42 0
	add	sp, sp, #20
.LVL706:
	mov	r0, r5
	@ sp needed for prologue
.LVL707:
.LVL708:
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE1429:
	.fnend
	.size	_ZNK15btCylinderShape24getHalfExtentsWithMarginEv, .-_ZNK15btCylinderShape24getHalfExtentsWithMarginEv
	.global	__aeabi_i2f
	.section	.text._ZN16btCollisionWorld15debugDrawObjectERK11btTransformPK16btCollisionShapeRK9btVector3,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorld15debugDrawObjectERK11btTransformPK16btCollisionShapeRK9btVector3
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld15debugDrawObjectERK11btTransformPK16btCollisionShapeRK9btVector3, %function
_ZN16btCollisionWorld15debugDrawObjectERK11btTransformPK16btCollisionShapeRK9btVector3:
	.fnstart
.LFB1642:
	.loc 8 1236 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI100:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL709:
	.pad #444
	sub	sp, sp, #444
.LCFI101:
	.cfi_def_cfa_offset 464
	.loc 8 1236 0
	str	r3, [sp, #16]
.LBB7105:
	.loc 8 1238 0
	ldr	r3, [r0]
.LVL710:
.LBE7105:
	.loc 8 1236 0
	str	r1, [sp, #20]
	mov	r6, r2
.LBB7311:
	.loc 8 1238 0
	ldr	r3, [r3, #20]
.LBE7311:
	.loc 8 1236 0
	mov	r5, r0
.LBB7312:
	.loc 8 1238 0
	blx	r3
.LVL711:
	ldr	r3, [r0]
	mov	r2, #254
	ldr	r1, [sp, #20]
	ldr	r3, [r3, #56]
	lsl	r2, r2, #22
	blx	r3
.LVL712:
.LBB7106:
.LBB7107:
.LBB7108:
	.file 29 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionShapes/btCollisionShape.h"
	.loc 29 111 0
	ldr	r3, [r6, #4]
.LBE7108:
.LBE7107:
	.loc 8 1240 0
	cmp	r3, #31
	bne	.L456
.LVL713:
	ldr	r4, [r6, #16]
	mov	r7, #80
	str	r4, [sp, #12]
	mul	r7, r4
.LBB7109:
.LBB7110:
	.loc 8 1243 0
	b	.L457
.LVL714:
.L458:
.LBB7111:
.LBB7112:
.LBB7113:
.LBB7114:
	.loc 10 172 0
	ldr	r1, [r6, #24]
.LBE7114:
.LBE7113:
.LBE7112:
	.loc 8 1245 0
	add	r0, sp, #348
.LBB7117:
.LBB7116:
.LBB7115:
	.loc 10 172 0
	add	r1, r1, r7
.LBE7115:
.LBE7116:
.LBE7117:
	.loc 8 1245 0
	bl	_ZN11btTransformC1ERKS_
.LVL715:
.LBB7118:
.LBB7119:
	.file 30 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionShapes/btCompoundShape.h"
	.loc 30 96 0
	ldr	r3, [r6, #24]
.LBE7119:
.LBE7118:
	.loc 8 1247 0
	add	r0, sp, #220
	ldr	r1, [sp, #20]
.LBB7122:
.LBB7120:
	.loc 30 96 0
	add	r3, r3, r7
	ldr	r3, [r3, #64]
.LBE7120:
.LBE7122:
	.loc 8 1247 0
	add	r2, sp, #348
.LBB7123:
.LBB7121:
	.loc 30 96 0
	str	r3, [sp, #24]
.LBE7121:
.LBE7123:
	.loc 8 1247 0
	ldr	r3, [r5]
	ldr	r4, [r3, #28]
	bl	_ZNK11btTransformmlERKS_
	mov	r0, r5
	add	r1, sp, #220
	ldr	r2, [sp, #24]
	ldr	r3, [sp, #16]
	blx	r4
.LVL716:
.L457:
.LBE7111:
	.loc 8 1243 0 discriminator 1
	ldr	r4, [sp, #12]
.LBB7124:
	.loc 8 1247 0
	sub	r7, r7, #80
.LBE7124:
	.loc 8 1243 0 discriminator 1
	sub	r4, r4, #1
	str	r4, [sp, #12]
	bpl	.L458
	b	.L455
.LVL717:
.L456:
.LBE7110:
.LBE7109:
.LBB7125:
	.loc 8 1253 0
	cmp	r3, #10
	beq	.L464
	bgt	.L468
	cmp	r3, #8
	beq	.L462
	bgt	.L471
	cmp	r3, #0
	beq	.L461
	b	.L460
.L468:
	cmp	r3, #13
	bne	.LCB8911
	b	.L466	@long jump
.LCB8911:
	cmp	r3, #28
	bne	.LCB8913
	b	.L467	@long jump
.LCB8913:
	cmp	r3, #11
	beq	.LCB8915
	b	.L460	@long jump
.LCB8915:
	b	.L502
.L461:
.LVL718:
.LBB7126:
.LBB7127:
	.loc 8 1259 0
	mov	r1, r6
	add	r0, sp, #348
	bl	_ZNK10btBoxShape24getHalfExtentsWithMarginEv
	.loc 8 1260 0
	ldr	r3, [r5]
	mov	r0, r5
.LBB7128:
.LBB7129:
	.loc 15 802 0
	mov	r5, #128
.LVL719:
.LBE7129:
.LBE7128:
	.loc 8 1260 0
	ldr	r3, [r3, #20]
	blx	r3
.LVL720:
	ldr	r3, [r0]
.LBB7142:
.LBB7139:
	.loc 15 802 0
	ldr	r2, [sp, #352]
.LBB7130:
.LBB7131:
.LBB7132:
	.loc 15 132 0
	ldr	r1, [sp, #348]
.LBE7132:
.LBE7131:
.LBE7130:
.LBE7139:
.LBE7142:
	.loc 8 1260 0
	ldr	r4, [r3, #72]
.LVL721:
.LBB7143:
.LBB7140:
	.loc 15 802 0
	ldr	r3, [sp, #356]
	lsl	r5, r5, #24
	add	r2, r2, r5
	add	r3, r3, r5
.LVL722:
.LBB7137:
.LBB7135:
.LBB7133:
	.loc 15 132 0
	add	r1, r1, r5
.LBE7133:
.LBE7135:
.LBE7137:
.LBE7140:
.LBE7143:
	.loc 8 1260 0
	ldr	r5, [sp, #16]
.LBB7144:
.LBB7141:
.LBB7138:
.LBB7136:
.LBB7134:
	.loc 15 134 0
	str	r3, [sp, #68]
	.loc 15 135 0
	mov	r3, #0
	.loc 15 132 0
	str	r1, [sp, #60]
	.loc 15 133 0
	str	r2, [sp, #64]
	.loc 15 135 0
	str	r3, [sp, #72]
.LBE7134:
.LBE7136:
.LBE7138:
.LBE7141:
.LBE7144:
	.loc 8 1260 0
	str	r5, [sp]
	add	r1, sp, #60
	add	r2, sp, #348
.LVL723:
	ldr	r3, [sp, #20]
	blx	r4
.LVL724:
	.loc 8 1261 0
	b	.L455
.LVL725:
.L462:
.LBE7127:
.LBB7145:
	.loc 8 1267 0
	ldr	r3, [r6]
	mov	r0, r6
	ldr	r3, [r3, #48]
	blx	r3
	.loc 8 1269 0
	ldr	r3, [r5]
	.loc 8 1267 0
	add	r6, r0, #0
.LVL726:
	.loc 8 1269 0
	mov	r0, r5
.LVL727:
	ldr	r3, [r3, #20]
	blx	r3
	ldr	r3, [r0]
	add	r1, r6, #0
	ldr	r2, [sp, #20]
	ldr	r4, [r3, #16]
	ldr	r3, [sp, #16]
	blx	r4
	.loc 8 1270 0
	b	.L455
.LVL728:
.L471:
.LBE7145:
.LBB7146:
	.loc 8 1277 0
	add	r4, sp, #348
.LVL729:
	mov	r0, r4
	bl	_ZN11btTransform11setIdentityEv
.LVL730:
	ldr	r7, [r6, #92]
.LBB7147:
.LBB7148:
.LBB7149:
	.loc 23 152 0
	add	r4, sp, #396
.LVL731:
	str	r4, [sp, #36]
.LBE7149:
.LBE7148:
.LBE7147:
	.loc 8 1277 0
	lsl	r0, r7, #4
	lsl	r1, r7, #2
	str	r0, [sp, #24]
	str	r1, [sp, #12]
.LBB7160:
	.loc 8 1279 0
	b	.L472
.LVL732:
.L473:
.LBB7152:
.LBB7150:
	.loc 23 152 0
	ldr	r4, [sp, #24]
	ldr	r3, [r6, #100]
	ldr	r2, [sp, #36]
	add	r3, r3, r4
	ldmia	r3!, {r0, r1, r4}
	stmia	r2!, {r0, r1, r4}
	ldr	r3, [r3]
.LBE7150:
.LBE7152:
	.loc 8 1282 0
	mov	r0, r5
.LBB7153:
.LBB7151:
	.loc 23 152 0
	str	r3, [r2]
.LBE7151:
.LBE7153:
	.loc 8 1282 0
	ldr	r3, [r5]
	ldr	r3, [r3, #20]
	blx	r3
.LVL733:
	ldr	r3, [r0]
	mov	r4, r0
.LBB7154:
.LBB7155:
	.file 31 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionShapes/btMultiSphereShape.h"
	.loc 31 59 0
	ldr	r0, [sp, #12]
.LBE7155:
.LBE7154:
	.loc 8 1282 0
	ldr	r3, [r3, #16]
	ldr	r1, [sp, #20]
	add	r2, sp, #348
.LVL734:
	str	r3, [sp, #28]
.LVL735:
.LBB7158:
.LBB7156:
	.loc 31 59 0
	ldr	r3, [r6, #120]
	ldr	r3, [r3, r0]
.LBE7156:
.LBE7158:
	.loc 8 1282 0
	add	r0, sp, #284
.LBB7159:
.LBB7157:
	.loc 31 59 0
	str	r3, [sp, #32]
.LBE7157:
.LBE7159:
	.loc 8 1282 0
	bl	_ZNK11btTransformmlERKS_
.LVL736:
	mov	r0, r4
	ldr	r1, [sp, #32]
	add	r2, sp, #284
	ldr	r3, [sp, #16]
	ldr	r4, [sp, #28]
	blx	r4
.LVL737:
.L472:
	ldr	r4, [sp, #24]
	sub	r4, r4, #16
	str	r4, [sp, #24]
	ldr	r4, [sp, #12]
	sub	r4, r4, #4
	str	r4, [sp, #12]
	.loc 8 1279 0 discriminator 1
	sub	r7, r7, #1
	bpl	.L473
	b	.L455
.LVL738:
.L464:
.LBE7160:
.LBE7146:
.LBB7161:
.LBB7162:
.LBB7163:
	.file 32 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionShapes/btCapsuleShape.h"
	.loc 32 86 0
	ldr	r7, [r6, #52]
.LVL739:
	mov	r1, #3
	add	r0, r7, #2
	bl	__aeabi_idivmod
.LVL740:
	.loc 32 87 0
	lsl	r1, r1, #2
	add	r1, r6, r1
.LBE7163:
.LBE7162:
.LBB7166:
.LBB7167:
	.loc 32 92 0
	lsl	r3, r7, #2
.LBE7167:
.LBE7166:
.LBB7170:
.LBB7164:
	.loc 32 87 0
	ldr	r1, [r1, #28]
.LBE7164:
.LBE7170:
.LBB7171:
.LBB7168:
	.loc 32 92 0
	add	r6, r6, r3
.LVL741:
.LBE7168:
.LBE7171:
	.loc 8 1295 0
	ldr	r3, [r5]
	mov	r0, r5
.LBB7172:
.LBB7165:
	.loc 32 87 0
	str	r1, [sp, #12]
.LBE7165:
.LBE7172:
	.loc 8 1295 0
	ldr	r3, [r3, #20]
.LBB7173:
.LBB7169:
	.loc 32 92 0
	ldr	r6, [r6, #28]
.LBE7169:
.LBE7173:
	.loc 8 1295 0
	blx	r3
	ldr	r4, [sp, #16]
	ldr	r5, [sp, #20]
.LVL742:
	ldr	r3, [r0]
	str	r4, [sp, #4]
	str	r5, [sp]
	ldr	r4, [r3, #76]
	b	.L501
.LVL743:
.L502:
.LBE7161:
.LBB7174:
.LBB7175:
.LBB7176:
	.file 33 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionShapes/btConeShape.h"
	.loc 33 44 0
	ldr	r4, [r6, #60]
.LBE7176:
.LBE7175:
	.loc 8 1305 0
	ldr	r3, [r5]
	mov	r0, r5
.LBB7178:
.LBB7177:
	.loc 33 44 0
	str	r4, [sp, #12]
.LBE7177:
.LBE7178:
	.loc 8 1305 0
	ldr	r3, [r3, #20]
.LBB7179:
.LBB7180:
	.loc 33 43 0
	ldr	r7, [r6, #56]
.LVL744:
.LBE7180:
.LBE7179:
.LBB7181:
.LBB7182:
	.loc 33 84 0
	ldr	r6, [r6, #68]
.LVL745:
.LBE7182:
.LBE7181:
	.loc 8 1305 0
	blx	r3
	ldr	r4, [sp, #16]
	ldr	r5, [sp, #20]
.LVL746:
	ldr	r3, [r0]
	ldr	r2, [sp, #12]
	str	r5, [sp]
	str	r4, [sp, #4]
	ldr	r4, [r3, #84]
	add	r1, r7, #0
	mov	r3, r6
.L500:
	blx	r4
	.loc 8 1306 0
	b	.L455
.LVL747:
.L466:
.LBE7174:
.LBB7183:
	.loc 8 1313 0
	ldr	r3, [r6]
	mov	r0, r6
.LBB7184:
.LBB7185:
	.loc 28 97 0
	ldr	r7, [r6, #52]
.LBE7185:
.LBE7184:
	.loc 8 1313 0
	ldr	r3, [r3, #92]
	blx	r3
	.loc 8 1314 0
	add	r4, sp, #76
	mov	r1, r6
	.loc 8 1313 0
	str	r0, [sp, #12]
.LVL748:
	.loc 8 1314 0
	mov	r0, r4
.LVL749:
	bl	_ZNK15btCylinderShape24getHalfExtentsWithMarginEv
.LVL750:
	lsl	r3, r7, #2
	ldr	r6, [r3, r4]
.LVL751:
	.loc 8 1315 0
	ldr	r3, [r5]
.LVL752:
	mov	r0, r5
	ldr	r3, [r3, #20]
	blx	r3
	ldr	r4, [sp, #16]
.LVL753:
	ldr	r5, [sp, #20]
.LVL754:
	ldr	r3, [r0]
	str	r4, [sp, #4]
	str	r5, [sp]
	ldr	r4, [r3, #80]
.LVL755:
.L501:
	ldr	r1, [sp, #12]
	add	r2, r6, #0
	mov	r3, r7
	b	.L500
.LVL756:
.L467:
.LBE7183:
.LBB7186:
	.loc 8 1324 0
	ldr	r3, [r5]
	mov	r0, r5
	.loc 8 1322 0
	ldr	r7, [r6, #64]
.LVL757:
	.loc 8 1324 0
	ldr	r3, [r3, #20]
	blx	r3
.LVL758:
	ldr	r5, [sp, #16]
.LVL759:
	ldr	r3, [r0]
	.loc 8 1323 0
	mov	r1, r6
	.loc 8 1324 0
	str	r5, [sp]
	ldr	r4, [r3, #88]
	.loc 8 1323 0
	add	r1, r1, #48
	.loc 8 1324 0
	add	r2, r7, #0
	ldr	r3, [sp, #20]
	blx	r4
	.loc 8 1325 0
	b	.L455
.LVL760:
.L460:
.LBE7186:
.LBB7187:
	.loc 8 1332 0
	cmp	r3, #6
	ble	.LCB9422
	b	.L474	@long jump
.LCB9422:
.LVL761:
.LBB7188:
.LBB7189:
.LBB7190:
.LBB7191:
	.file 34 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionShapes/btPolyhedralConvexShape.h"
	.loc 34 48 0
	ldr	r7, [r6, #52]
.LBE7191:
.LBE7190:
	.loc 8 1337 0
	mov	r4, #0
	str	r4, [sp, #12]
	cmp	r7, r4
	beq	.LCB9435
	b	.L499	@long jump
.LCB9435:
	b	.L476
.LVL762:
.L484:
.LBB7192:
.LBB7193:
.LBB7194:
.LBB7195:
.LBB7196:
.LBB7197:
	.loc 15 132 0
	mov	r0, #0
	str	r0, [sp, #188]
	.loc 15 133 0
	str	r0, [sp, #192]
	.loc 15 134 0
	str	r0, [sp, #196]
	.loc 15 135 0
	str	r0, [sp, #200]
.LVL763:
	.loc 8 1235 0
	ldr	r0, [sp, #12]
	mov	r2, #36
	mov	r4, r2
	mul	r4, r0
.LVL764:
.LBE7197:
.LBE7196:
.LBE7195:
.LBB7200:
.LBB7201:
	.loc 10 172 0
	ldr	r2, [r7, #36]
.LBE7201:
.LBE7200:
.LBB7203:
.LBB7199:
.LBB7198:
	.loc 8 1235 0
	str	r4, [sp, #28]
.LBE7198:
.LBE7199:
.LBE7203:
.LBB7204:
.LBB7202:
	.loc 10 172 0
	add	r2, r2, r4
.LVL765:
.LBE7202:
.LBE7204:
.LBB7205:
.LBB7206:
	.loc 10 151 0
	ldr	r4, [r2, #4]
	str	r4, [sp, #32]
.LBE7206:
.LBE7205:
.LBB7207:
	.loc 8 1344 0
	cmp	r4, #0
	beq	.L478
.LVL766:
.LBB7208:
.LBB7209:
.LBB7210:
	.loc 10 172 0
	mov	r1, r4
.LBE7210:
.LBE7209:
	.loc 8 1346 0
	ldr	r2, [r2, #12]
.LVL767:
.LBB7212:
.LBB7211:
	.loc 10 172 0
	sub	r1, r1, #1
.LVL768:
.LBE7211:
.LBE7212:
	.loc 8 1346 0
	lsl	r1, r1, #2
	ldr	r1, [r1, r2]
.LBB7213:
	.loc 8 1347 0
	mov	r4, #0
.LVL769:
	str	r4, [sp, #24]
.LBE7213:
	.loc 8 1346 0
	str	r1, [sp, #36]
.LVL770:
.LBB7241:
	.loc 8 1347 0
	b	.L479
.LVL771:
.L480:
.LBB7214:
	.loc 8 1349 0
	ldr	r4, [sp, #24]
.LVL772:
	ldr	r3, [r3, #12]
.LVL773:
.LBB7215:
.LBB7216:
	.loc 10 172 0
	ldr	r1, [r7, #16]
.LBE7216:
.LBE7215:
	.loc 8 1349 0
	lsl	r2, r4, #2
	ldr	r2, [r2, r3]
	.loc 8 1350 0
	add	r0, sp, #188
.LBB7219:
.LBB7217:
	.loc 10 172 0
	lsl	r4, r2, #4
	add	r1, r1, r4
.LBE7217:
.LBE7219:
	.loc 8 1349 0
	str	r2, [sp, #40]
.LVL774:
.LBB7220:
.LBB7218:
	.loc 10 172 0
	str	r4, [sp, #44]
.LBE7218:
.LBE7220:
	.loc 8 1350 0
	bl	_ZN9btVector3pLERKS_
.LVL775:
	.loc 8 1351 0
	ldr	r3, [r5]
	mov	r0, r5
	ldr	r3, [r3, #20]
	blx	r3
	ldr	r3, [r0]
.LBB7221:
.LBB7222:
	.loc 10 172 0
	ldr	r1, [sp, #36]
.LBE7222:
.LBE7221:
	.loc 8 1351 0
	mov	r4, r0
.LBB7225:
.LBB7223:
	.loc 10 172 0
	ldr	r0, [r7, #16]
.LBE7223:
.LBE7225:
	.loc 8 1351 0
	ldr	r3, [r3, #8]
.LBB7226:
.LBB7224:
	.loc 10 172 0
	lsl	r2, r1, #4
	add	r2, r0, r2
	str	r0, [sp, #48]
.LBE7224:
.LBE7226:
.LBB7227:
.LBB7228:
	.loc 23 102 0
	ldr	r1, [sp, #20]
	add	r0, sp, #92
.LBE7228:
.LBE7227:
	.loc 8 1351 0
	str	r3, [sp, #52]
.LVL776:
.LBB7230:
.LBB7229:
	.loc 23 102 0
	bl	_ZNK11btTransformclERK9btVector3
.LVL777:
.LBE7229:
.LBE7230:
.LBB7231:
.LBB7232:
	.loc 10 172 0
	ldr	r3, [sp, #48]
	ldr	r0, [sp, #44]
.LBE7232:
.LBE7231:
.LBB7234:
.LBB7235:
	.loc 23 102 0
	ldr	r1, [sp, #20]
.LBE7235:
.LBE7234:
.LBB7237:
.LBB7233:
	.loc 10 172 0
	add	r2, r3, r0
.LBE7233:
.LBE7237:
.LBB7238:
.LBB7236:
	.loc 23 102 0
	add	r0, sp, #108
	bl	_ZNK11btTransformclERK9btVector3
.LBE7236:
.LBE7238:
	.loc 8 1351 0
	mov	r0, r4
	add	r1, sp, #92
	ldr	r4, [sp, #52]
	add	r2, sp, #108
	ldr	r3, [sp, #16]
	blx	r4
.LVL778:
.LBE7214:
	.loc 8 1347 0 discriminator 2
	ldr	r4, [sp, #24]
	add	r4, r4, #1
	str	r4, [sp, #24]
.LVL779:
	.loc 8 1352 0
	ldr	r4, [sp, #40]
.LVL780:
	str	r4, [sp, #36]
.LVL781:
.L479:
.LBB7239:
.LBB7240:
	.loc 10 172 0
	ldr	r4, [sp, #28]
	ldr	r3, [r7, #36]
	add	r3, r3, r4
.LVL782:
.LBE7240:
.LBE7239:
	.loc 8 1347 0 discriminator 1
	ldr	r2, [r3, #4]
	ldr	r4, [sp, #24]
	cmp	r4, r2
	blt	.L480
.LVL783:
.L478:
.LBE7241:
.LBE7208:
.LBE7207:
	.loc 8 1355 0
	ldr	r0, [sp, #32]
	bl	__aeabi_i2f
	add	r1, r0, #0
	mov	r0, #254
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
	add	r4, r0, #0
.LVL784:
.LBB7242:
.LBB7243:
	.loc 15 205 0
	add	r1, r4, #0
	ldr	r0, [sp, #188]
	bl	__aeabi_fmul
	.loc 15 206 0
	add	r1, r4, #0
	.loc 15 205 0
	str	r0, [sp, #188]
	.loc 15 206 0
	ldr	r0, [sp, #192]
	bl	__aeabi_fmul
	.loc 15 207 0
	add	r1, r4, #0
	.loc 15 206 0
	str	r0, [sp, #192]
	.loc 15 207 0
	ldr	r0, [sp, #196]
	bl	__aeabi_fmul
.LBE7243:
.LBE7242:
.LBB7245:
	.loc 8 1356 0
	ldr	r3, [r5]
.LBE7245:
.LBB7269:
.LBB7244:
	.loc 15 207 0
	str	r0, [sp, #196]
.LBE7244:
.LBE7269:
.LBB7270:
	.loc 8 1356 0
	mov	r0, r5
	ldr	r3, [r3, #20]
	blx	r3
	ldr	r3, [r0]
	ldr	r3, [r3, #48]
	blx	r3
	lsl	r1, r0, #17
	bpl	.L481
.LVL785:
.LBB7246:
.LBB7247:
.LBB7248:
.LBB7249:
	.loc 15 132 0
	mov	r2, #254
	lsl	r2, r2, #22
	.loc 15 134 0
	mov	r3, #0
	.loc 15 132 0
	str	r2, [sp, #204]
	.loc 15 133 0
	str	r2, [sp, #208]
	.loc 15 134 0
	str	r3, [sp, #212]
	.loc 15 135 0
	str	r3, [sp, #216]
.LVL786:
.LBE7249:
.LBE7248:
.LBE7247:
.LBB7250:
.LBB7251:
	.loc 10 172 0
	ldr	r3, [r7, #36]
	ldr	r4, [sp, #28]
.LBE7251:
.LBE7250:
.LBB7253:
.LBB7254:
.LBB7255:
	.loc 15 135 0
	mov	r0, #0
.LBE7255:
.LBE7254:
.LBE7253:
.LBB7260:
.LBB7252:
	.loc 10 172 0
	add	r3, r3, r4
.LVL787:
.LBE7252:
.LBE7260:
.LBB7261:
.LBB7258:
.LBB7256:
	.loc 15 132 0
	ldr	r2, [r3, #20]
	str	r2, [sp, #348]
	.loc 15 133 0
	ldr	r2, [r3, #24]
	str	r2, [sp, #352]
	.loc 15 134 0
	ldr	r3, [r3, #28]
.LVL788:
	.loc 15 135 0
	str	r0, [sp, #360]
.LBE7256:
.LBE7258:
.LBE7261:
	.loc 8 1360 0
	mov	r0, r5
.LBB7262:
.LBB7259:
.LBB7257:
	.loc 15 134 0
	str	r3, [sp, #356]
.LBE7257:
.LBE7259:
.LBE7262:
	.loc 8 1360 0
	ldr	r3, [r5]
	ldr	r3, [r3, #20]
	blx	r3
	ldr	r3, [r0]
	str	r0, [sp, #24]
.LBB7263:
.LBB7264:
	.loc 23 102 0
	ldr	r1, [sp, #20]
	add	r0, sp, #124
	add	r2, sp, #188
.LBE7264:
.LBE7263:
	.loc 8 1360 0
	ldr	r4, [r3, #8]
.LVL789:
.LBB7266:
.LBB7265:
	.loc 23 102 0
	bl	_ZNK11btTransformclERK9btVector3
.LBE7265:
.LBE7266:
	.loc 8 1360 0
	add	r0, sp, #140
	add	r1, sp, #188
	add	r2, sp, #348
.LVL790:
	bl	_ZplRK9btVector3S1_
.LVL791:
.LBB7267:
.LBB7268:
	.loc 23 102 0
	add	r0, sp, #156
	ldr	r1, [sp, #20]
	add	r2, sp, #140
.LVL792:
	bl	_ZNK11btTransformclERK9btVector3
.LVL793:
.LBE7268:
.LBE7267:
	.loc 8 1360 0
	ldr	r0, [sp, #24]
	add	r1, sp, #124
	add	r2, sp, #156
	add	r3, sp, #204
	blx	r4
.LVL794:
.L481:
.LBE7246:
.LBE7270:
.LBE7194:
	.loc 8 1340 0
	ldr	r4, [sp, #12]
	add	r4, r4, #1
	str	r4, [sp, #12]
.LVL795:
.L499:
	.loc 8 1340 0 is_stmt 0 discriminator 1
	ldr	r3, [r7, #28]
	ldr	r4, [sp, #12]
	cmp	r4, r3
	bge	.LCB9910
	b	.L484	@long jump
.LCB9910:
	b	.L474
.LVL796:
.L485:
.LBE7193:
.LBE7192:
.LBB7271:
.LBB7272:
	.loc 8 1371 0 is_stmt 1
	ldr	r3, [r6]
	mov	r1, r7
	mov	r0, r6
	ldr	r4, [r3, #104]
	add	r2, sp, #172
	add	r3, sp, #188
.LVL797:
	blx	r4
.LVL798:
.LBB7273:
.LBB7274:
	.loc 23 102 0
	add	r0, sp, #204
	ldr	r1, [sp, #20]
	add	r2, sp, #172
	bl	_ZNK11btTransformclERK9btVector3
.LVL799:
.LBE7274:
.LBE7273:
.LBB7275:
.LBB7276:
	ldr	r1, [sp, #20]
	add	r2, sp, #188
.LVL800:
	add	r0, sp, #348
	bl	_ZNK11btTransformclERK9btVector3
.LVL801:
.LBE7276:
.LBE7275:
	.loc 8 1374 0
	ldr	r3, [r5]
	mov	r0, r5
.LBE7272:
	.loc 8 1368 0 discriminator 2
	add	r7, r7, #1
.LVL802:
.LBB7277:
	.loc 8 1374 0
	ldr	r3, [r3, #20]
	blx	r3
	ldr	r3, [r0]
	add	r1, sp, #204
	add	r2, sp, #348
	ldr	r4, [r3, #8]
	ldr	r3, [sp, #16]
	blx	r4
.LVL803:
.L476:
.LBE7277:
	.loc 8 1368 0 discriminator 1
	ldr	r3, [r6]
	mov	r0, r6
	ldr	r3, [r3, #100]
	blx	r3
	cmp	r7, r0
	blt	.L485
.LVL804:
.L474:
.LBE7271:
.LBE7189:
.LBE7188:
.LBE7187:
.LBB7278:
.LBB7279:
.LBB7280:
.LBB7281:
	.file 35 "jni/../../../bullet4droid/jni/src/BulletCollision/BroadphaseCollision/btBroadphaseProxy.h"
	.loc 35 152 0
	ldr	r3, [r6, #4]
	sub	r3, r3, #21
.LBE7281:
.LBE7280:
.LBE7279:
	.loc 8 1381 0
	cmp	r3, #8
	bhi	.L487
.LVL805:
.LBB7282:
.LBB7283:
.LBB7284:
.LBB7285:
	.loc 15 132 0
	ldr	r3, .L503
	.loc 15 135 0
	mov	r2, #0
	str	r2, [sp, #200]
.LVL806:
	.loc 15 132 0
	str	r3, [sp, #188]
	.loc 15 133 0
	str	r3, [sp, #192]
	.loc 15 134 0
	str	r3, [sp, #196]
.LBE7285:
.LBE7284:
.LBE7283:
.LBB7286:
.LBB7287:
.LBB7288:
	.loc 15 132 0
	ldr	r3, .L503+4
	.loc 15 135 0
	str	r2, [sp, #216]
.LBE7288:
.LBE7287:
.LBE7286:
	.loc 8 1389 0
	mov	r0, r5
.LBB7291:
.LBB7290:
.LBB7289:
	.loc 15 132 0
	str	r3, [sp, #204]
	.loc 15 133 0
	str	r3, [sp, #208]
	.loc 15 134 0
	str	r3, [sp, #212]
.LBE7289:
.LBE7290:
.LBE7291:
	.loc 8 1389 0
	ldr	r3, [r5]
	ldr	r3, [r3, #20]
	blx	r3
.LVL807:
.LBB7292:
.LBB7293:
.LBB7294:
	.loc 8 1201 0
	ldr	r3, .L503+8
	str	r0, [sp, #356]
.LPIC107:
	add	r3, pc
	ldr	r3, [r3]
	mov	r2, r3
	add	r2, r2, #8
	str	r2, [sp, #348]
	ldr	r2, [sp, #16]
	add	r3, r3, #32
	str	r3, [sp, #352]
	add	r3, sp, #360
	ldmia	r2!, {r0, r1, r4}
	stmia	r3!, {r0, r1, r4}
.LVL808:
	ldr	r2, [r2]
	add	r0, sp, #376
	str	r2, [r3]
	ldr	r1, [sp, #20]
	bl	_ZN11btTransformC1ERKS_
.LVL809:
.LBE7294:
.LBE7293:
.LBE7292:
	.loc 8 1390 0
	ldr	r3, [r6]
	mov	r0, r6
	add	r1, sp, #348
.LVL810:
	ldr	r4, [r3, #64]
	add	r2, sp, #204
.LVL811:
	add	r3, sp, #188
.LVL812:
	blx	r4
.LVL813:
	add	r0, sp, #348
.LVL814:
	bl	_ZN17DebugDrawcallbackD1Ev
.LVL815:
.L487:
.LBE7282:
.LBE7278:
.LBB7295:
	.loc 8 1394 0
	ldr	r3, [r6, #4]
	cmp	r3, #3
	bne	.L455
.LVL816:
.LBB7296:
.LBB7297:
.LBB7298:
.LBB7299:
	.loc 15 132 0
	ldr	r3, .L503
	.loc 15 135 0
	mov	r2, #0
	str	r2, [sp, #200]
.LVL817:
	.loc 15 132 0
	str	r3, [sp, #188]
	.loc 15 133 0
	str	r3, [sp, #192]
	.loc 15 134 0
	str	r3, [sp, #196]
.LBE7299:
.LBE7298:
.LBE7297:
.LBB7300:
.LBB7301:
.LBB7302:
	.loc 15 132 0
	ldr	r3, .L503+4
	.loc 15 135 0
	str	r2, [sp, #216]
.LBE7302:
.LBE7301:
.LBE7300:
	.loc 8 1401 0
	mov	r0, r5
.LBB7305:
.LBB7304:
.LBB7303:
	.loc 15 132 0
	str	r3, [sp, #204]
	.loc 15 133 0
	str	r3, [sp, #208]
	.loc 15 134 0
	str	r3, [sp, #212]
.LBE7303:
.LBE7304:
.LBE7305:
	.loc 8 1401 0
	ldr	r3, [r5]
	ldr	r3, [r3, #20]
	blx	r3
.LVL818:
.LBB7306:
.LBB7307:
.LBB7308:
	.loc 8 1201 0
	ldr	r3, .L503+12
	str	r0, [sp, #356]
.LPIC106:
	add	r3, pc
	ldr	r3, [r3]
	mov	r2, r3
	add	r2, r2, #8
	str	r2, [sp, #348]
	ldr	r2, [sp, #16]
	add	r3, r3, #32
	str	r3, [sp, #352]
	add	r3, sp, #360
	ldmia	r2!, {r0, r1, r5}
	stmia	r3!, {r0, r1, r5}
.LVL819:
	ldr	r2, [r2]
	add	r0, sp, #376
	str	r2, [r3]
	ldr	r1, [sp, #20]
	bl	_ZN11btTransformC1ERKS_
.LVL820:
.LBE7308:
.LBE7307:
.LBE7306:
.LBB7309:
.LBB7310:
	.file 36 "jni/../../../bullet4droid/jni/src/BulletCollision/CollisionShapes/btConvexTriangleMeshShape.h"
	.loc 36 37 0
	ldr	r0, [r6, #92]
.LBE7310:
.LBE7309:
	.loc 8 1402 0
	add	r1, sp, #352
.LVL821:
	add	r2, sp, #204
.LVL822:
	ldr	r3, [r0]
	ldr	r4, [r3, #8]
	add	r3, sp, #188
.LVL823:
	blx	r4
.LVL824:
	add	r0, sp, #348
.LVL825:
	bl	_ZN17DebugDrawcallbackD1Ev
.LVL826:
.L455:
.LBE7296:
.LBE7295:
.LBE7126:
.LBE7125:
.LBE7106:
.LBE7312:
	.loc 8 1411 0
	add	sp, sp, #444
	@ sp needed for prologue
	pop	{r4, r5, r6, r7, pc}
.L504:
	.align	2
.L503:
	.word	1566444395
	.word	-581039253
	.word	_ZTV17DebugDrawcallback(GOT_PREL)+(.-(.LPIC107+4))
	.word	_ZTV17DebugDrawcallback(GOT_PREL)+(.-(.LPIC106+4))
	.cfi_endproc
.LFE1642:
	.fnend
	.size	_ZN16btCollisionWorld15debugDrawObjectERK11btTransformPK16btCollisionShapeRK9btVector3, .-_ZN16btCollisionWorld15debugDrawObjectERK11btTransformPK16btCollisionShapeRK9btVector3
	.section	.text._ZN16btCollisionWorldC2EP12btDispatcherP21btBroadphaseInterfaceP24btCollisionConfiguration,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorldC2EP12btDispatcherP21btBroadphaseInterfaceP24btCollisionConfiguration
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorldC2EP12btDispatcherP21btBroadphaseInterfaceP24btCollisionConfiguration, %function
_ZN16btCollisionWorldC2EP12btDispatcherP21btBroadphaseInterfaceP24btCollisionConfiguration:
	.fnstart
.LFB1487:
	.loc 8 69 0
	.cfi_startproc
	.save	{r4, r5, lr}
	push	{r4, r5, lr}
.LCFI102:
	.cfi_def_cfa_offset 12
	.cfi_offset 4, -12
	.cfi_offset 5, -8
	.cfi_offset 14, -4
.LVL827:
	.loc 8 69 0
	ldr	r3, .L510
.LVL828:
.LBB7313:
.LBB7314:
.LBB7315:
.LBB7316:
	.file 37 "jni/../../../bullet4droid/jni/src/BulletCollision/BroadphaseCollision/btDispatcher.h"
	.loc 37 49 0
	mov	r5, #254
	lsl	r5, r5, #22
.LBE7316:
.LBE7315:
.LBE7314:
.LBE7313:
	.loc 8 69 0
.LPIC109:
	add	r3, pc
.LBB7347:
	.loc 8 73 0
	ldr	r3, [r3]
.LBB7329:
.LBB7323:
.LBB7317:
	.loc 37 49 0
	str	r5, [r0, #40]
	mov	r5, r0
.LBE7317:
.LBE7323:
.LBE7329:
	.loc 8 73 0
	add	r3, r3, #8
	str	r3, [r0]
.LVL829:
	str	r1, [r0, #24]
.LVL830:
.LBB7330:
.LBB7331:
.LBB7332:
.LBB7333:
	.loc 10 89 0
	mov	r3, #0
	.loc 10 88 0
	mov	r4, #1
.LBE7333:
.LBE7332:
.LBE7331:
.LBE7330:
.LBB7340:
.LBB7324:
.LBB7318:
	.loc 37 49 0
	add	r5, r5, #44
	mov	r1, #0
.LVL831:
.LBE7318:
.LBE7324:
.LBE7340:
.LBB7341:
.LBB7338:
.LBB7336:
.LBB7334:
	.loc 10 89 0
	str	r3, [r0, #16]
	.loc 10 90 0
	str	r3, [r0, #8]
	.loc 10 91 0
	str	r3, [r0, #12]
.LBE7334:
.LBE7336:
.LBE7338:
.LBE7341:
.LBB7342:
.LBB7325:
.LBB7319:
	.loc 37 49 0
	str	r3, [r0, #32]
.LBE7319:
.LBE7325:
.LBE7342:
.LBB7343:
.LBB7339:
.LBB7337:
.LBB7335:
	.loc 10 88 0
	strb	r4, [r0, #20]
.LBE7335:
.LBE7337:
.LBE7339:
.LBE7343:
.LBB7344:
.LBB7326:
.LBB7320:
	.loc 37 49 0
	str	r1, [r0, #28]
	str	r4, [r0, #36]
	strb	r4, [r5]
	str	r3, [r0, #48]
	strb	r3, [r5, #8]
	strb	r4, [r5, #9]
	strb	r4, [r5, #10]
	ldr	r5, .L510+4
.LBE7320:
.LBE7326:
.LBE7344:
.LBE7347:
	.loc 8 75 0
	@ sp needed for prologue
.LBB7348:
.LBB7345:
.LBB7327:
.LBB7321:
	.loc 37 49 0
	str	r5, [r0, #56]
	mov	r5, r0
	add	r5, r5, #60
	strb	r3, [r5]
.LBE7321:
.LBE7327:
.LBE7345:
	.loc 8 73 0
	str	r3, [r0, #72]
	mov	r3, r0
	add	r3, r3, #76
.LBB7346:
.LBB7328:
.LBB7322:
	.loc 37 49 0
	str	r1, [r0, #64]
.LBE7322:
.LBE7328:
.LBE7346:
	.loc 8 73 0
	str	r2, [r0, #68]
	strb	r4, [r3]
.LBE7348:
	.loc 8 75 0
	pop	{r4, r5, pc}
.L511:
	.align	2
.L510:
	.word	_ZTV16btCollisionWorld(GOT_PREL)+(.-(.LPIC109+4))
	.word	1025758986
	.cfi_endproc
.LFE1487:
	.fnend
	.size	_ZN16btCollisionWorldC2EP12btDispatcherP21btBroadphaseInterfaceP24btCollisionConfiguration, .-_ZN16btCollisionWorldC2EP12btDispatcherP21btBroadphaseInterfaceP24btCollisionConfiguration
	.section	.text._ZN16btCollisionWorld16updateSingleAabbEP17btCollisionObject,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorld16updateSingleAabbEP17btCollisionObject
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld16updateSingleAabbEP17btCollisionObject, %function
_ZN16btCollisionWorld16updateSingleAabbEP17btCollisionObject:
	.fnstart
.LFB1494:
	.loc 8 148 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI103:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL832:
.LBB7349:
.LBB7350:
.LBB7351:
	.loc 9 216 0
	mov	r7, r1
	add	r7, r7, #192
.LBE7351:
.LBE7350:
.LBE7349:
	.loc 8 148 0
	mov	r5, r0
.LBB7391:
.LBB7353:
.LBB7352:
	.loc 9 216 0
	ldr	r0, [r7]
.LVL833:
.LBE7352:
.LBE7353:
.LBE7391:
	.loc 8 148 0
	.pad #108
	sub	sp, sp, #108
.LCFI104:
	.cfi_def_cfa_offset 128
.LVL834:
.LBB7392:
	.loc 8 150 0
	add	r2, sp, #8
	ldr	r3, [r0]
.LBE7392:
	.loc 8 148 0
	mov	r6, r1
.LBB7393:
	.loc 8 150 0
	add	r1, r1, #4
.LVL835:
	ldr	r4, [r3, #8]
	add	r3, sp, #24
	blx	r4
.LVL836:
	ldr	r3, .L525
.LBB7354:
.LBB7355:
	.loc 15 187 0
	ldr	r0, [sp, #8]
.LBE7355:
.LBE7354:
	.loc 8 150 0
.LPIC117:
	add	r3, pc
	.loc 8 1535 0
	ldr	r3, [r3]
	ldr	r4, [r3]
.LVL837:
.LBB7359:
.LBB7360:
.LBB7361:
	.loc 15 135 0
	mov	r3, #0
	str	r3, [sp, #52]
.LVL838:
.LBE7361:
.LBE7360:
.LBE7359:
.LBB7364:
.LBB7356:
	.loc 15 187 0
	add	r1, r4, #0
.LBE7356:
.LBE7364:
.LBB7365:
.LBB7363:
.LBB7362:
	.loc 15 132 0
	str	r4, [sp, #40]
	.loc 15 133 0
	str	r4, [sp, #44]
	.loc 15 134 0
	str	r4, [sp, #48]
.LBE7362:
.LBE7363:
.LBE7365:
.LBB7366:
.LBB7357:
	.loc 15 187 0
	bl	__aeabi_fsub
	.loc 15 188 0
	add	r1, r4, #0
	.loc 15 187 0
	str	r0, [sp, #8]
	.loc 15 188 0
	ldr	r0, [sp, #12]
	bl	__aeabi_fsub
	.loc 15 189 0
	add	r1, r4, #0
	.loc 15 188 0
	str	r0, [sp, #12]
	.loc 15 189 0
	ldr	r0, [sp, #16]
	bl	__aeabi_fsub
.LBE7357:
.LBE7366:
	.loc 8 154 0
	add	r1, sp, #40
.LBB7367:
.LBB7358:
	.loc 15 189 0
	str	r0, [sp, #16]
.LBE7358:
.LBE7367:
	.loc 8 154 0
	add	r0, sp, #24
	bl	_ZN9btVector3pLERKS_
.LVL839:
.LBB7368:
	.loc 8 156 0
	mov	r3, r5
	add	r3, r3, #44
	ldrb	r3, [r3]
	cmp	r3, #0
	beq	.L516
.LVL840:
.LBB7369:
.LBB7370:
	.loc 9 288 0
	mov	r3, r6
	add	r3, r3, #236
.LBE7370:
.LBE7369:
	.loc 8 156 0 discriminator 1
	ldr	r3, [r3]
	cmp	r3, #2
	bne	.L516
.LVL841:
.LBB7371:
.LBB7372:
	.loc 9 191 0
	mov	r3, r6
	add	r3, r3, #204
	ldr	r3, [r3]
.LBE7372:
.LBE7371:
	.loc 8 156 0 discriminator 3
	lsl	r2, r3, #30
	bne	.L516
.LVL842:
.LBB7373:
.LBB7374:
.LBB7375:
	.loc 9 216 0
	ldr	r0, [r7]
.LVL843:
.LBE7375:
.LBE7374:
	.loc 8 159 0
	mov	r1, r6
	add	r2, sp, #56
	ldr	r3, [r0]
	add	r1, r1, #68
	ldr	r4, [r3, #8]
	add	r3, sp, #72
	blx	r4
.LVL844:
.LBB7376:
.LBB7377:
	.loc 15 187 0
	ldr	r0, [sp, #56]
	ldr	r1, [sp, #40]
	bl	__aeabi_fsub
	.loc 15 188 0
	ldr	r1, [sp, #44]
	.loc 15 187 0
	str	r0, [sp, #56]
	.loc 15 188 0
	ldr	r0, [sp, #60]
	bl	__aeabi_fsub
	.loc 15 189 0
	ldr	r1, [sp, #48]
	.loc 15 188 0
	str	r0, [sp, #60]
	.loc 15 189 0
	ldr	r0, [sp, #64]
	bl	__aeabi_fsub
.LBE7377:
.LBE7376:
	.loc 8 161 0
	add	r1, sp, #40
.LBB7379:
.LBB7378:
	.loc 15 189 0
	str	r0, [sp, #64]
.LBE7378:
.LBE7379:
	.loc 8 161 0
	add	r0, sp, #72
	bl	_ZN9btVector3pLERKS_
	.loc 8 162 0
	add	r0, sp, #8
	add	r1, sp, #56
	bl	_ZN9btVector36setMinERKS_
	.loc 8 163 0
	add	r0, sp, #24
	add	r1, sp, #72
	bl	_ZN9btVector36setMaxERKS_
.LVL845:
.L516:
.LBE7373:
.LBE7368:
.LBB7380:
.LBB7381:
.LBB7382:
	.loc 9 181 0
	mov	r3, r6
	add	r3, r3, #204
	ldr	r4, [r3]
	mov	r3, #1
.LBE7382:
.LBE7381:
.LBE7380:
	.loc 8 166 0
	ldr	r7, [r5, #68]
.LVL846:
.LBB7390:
.LBB7384:
.LBB7383:
	.loc 9 181 0
	and	r4, r3
.LBE7383:
.LBE7384:
	.loc 8 169 0
	bne	.L519
	.loc 8 169 0 is_stmt 0 discriminator 2
	add	r0, sp, #88
	add	r1, sp, #24
	add	r2, sp, #8
	bl	_ZmiRK9btVector3S1_
.LVL847:
.LBB7385:
.LBB7386:
	.loc 15 258 0 is_stmt 1
	add	r0, sp, #88
.LVL848:
	mov	r1, r0
	bl	_ZNK9btVector33dotERKS_
.LVL849:
.LBE7386:
.LBE7385:
	.loc 8 169 0 discriminator 2
	ldr	r1, .L525+4
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L524
.LVL850:
.L519:
	.loc 8 171 0
	ldr	r2, [r5, #24]
	ldr	r3, [r7]
.LBB7387:
.LBB7388:
	.loc 9 309 0
	add	r6, r6, #188
.LVL851:
.LBE7388:
.LBE7387:
	.loc 8 171 0
	ldr	r1, [r6]
	str	r2, [sp]
	ldr	r4, [r3, #16]
	mov	r0, r7
	add	r2, sp, #8
	add	r3, sp, #24
	blx	r4
	b	.L512
.LVL852:
.L523:
.LBB7389:
	.loc 8 179 0 discriminator 1
	ldr	r0, [r5, #72]
	cmp	r0, #0
	beq	.L512
	.loc 8 181 0
	strb	r4, [r3]
	.loc 8 182 0
	ldr	r1, .L525+8
	ldr	r3, [r0]
.LPIC112:
	add	r1, pc
	ldr	r3, [r3, #36]
	blx	r3
	.loc 8 183 0
	ldr	r0, [r5, #72]
	ldr	r1, .L525+12
	ldr	r3, [r0]
.LPIC113:
	add	r1, pc
	ldr	r3, [r3, #36]
	blx	r3
	.loc 8 184 0
	ldr	r0, [r5, #72]
	ldr	r1, .L525+16
	ldr	r3, [r0]
.LPIC114:
	add	r1, pc
	ldr	r3, [r3, #36]
	blx	r3
	.loc 8 185 0
	ldr	r0, [r5, #72]
	ldr	r1, .L525+20
	ldr	r3, [r0]
.LPIC115:
	add	r1, pc
	ldr	r3, [r3, #36]
	blx	r3
	b	.L512
.L524:
	.loc 8 176 0
	mov	r0, r6
	mov	r1, #5
	bl	_ZNK17btCollisionObject18setActivationStateEi
	.loc 8 179 0
	ldr	r3, .L525+24
.LPIC116:
	add	r3, pc
	ldrb	r2, [r3]
	cmp	r2, #0
	bne	.L523
.LVL853:
.L512:
.LBE7389:
.LBE7390:
.LBE7393:
	.loc 8 188 0
	add	sp, sp, #108
	@ sp needed for prologue
.LVL854:
.LVL855:
	pop	{r4, r5, r6, r7, pc}
.L526:
	.align	2
.L525:
	.word	gContactBreakingThreshold(GOT_PREL)+(.-(.LPIC117+4))
	.word	1399379109
	.word	.LC3-(.LPIC112+4)
	.word	.LC4-(.LPIC113+4)
	.word	.LC5-(.LPIC114+4)
	.word	.LC6-(.LPIC115+4)
	.word	.LANCHOR2-(.LPIC116+4)
	.cfi_endproc
.LFE1494:
	.fnend
	.size	_ZN16btCollisionWorld16updateSingleAabbEP17btCollisionObject, .-_ZN16btCollisionWorld16updateSingleAabbEP17btCollisionObject
	.section	.text._ZN16btCollisionWorld11updateAabbsEv,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorld11updateAabbsEv
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld11updateAabbsEv, %function
_ZN16btCollisionWorld11updateAabbsEv:
	.fnstart
.LFB1495:
	.loc 8 191 0
	.cfi_startproc
	.save	{r3, r4, r5, lr}
	push	{r3, r4, r5, lr}
.LCFI105:
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	.cfi_offset 4, -12
	.cfi_offset 5, -8
	.cfi_offset 14, -4
.LVL856:
	.loc 8 191 0
	mov	r4, r0
.LBB7394:
.LBB7395:
.LBB7396:
.LBB7397:
	.loc 14 181 0
	ldr	r0, .L536
.LVL857:
	.loc 8 195 0
	mov	r5, #0
	.loc 14 181 0
.LPIC118:
	add	r0, pc
	bl	_ZN15CProfileManager13Start_ProfileEPKc
	b	.L533
.LVL858:
.L534:
.LBE7397:
.LBE7396:
.LBE7395:
.LBB7398:
.LBB7399:
	.loc 8 197 0
	ldr	r3, [r4, #16]
	lsl	r2, r5, #2
	ldr	r1, [r2, r3]
.LVL859:
	.loc 8 200 0
	mov	r3, r4
	add	r3, r3, #76
	ldrb	r3, [r3]
	cmp	r3, #0
	bne	.L529
.LVL860:
.LBB7400:
.LBB7401:
.LBB7402:
.LBB7403:
	.loc 9 236 0
	mov	r3, r1
	add	r3, r3, #216
	ldr	r3, [r3]
.LBE7403:
.LBE7402:
	.loc 9 255 0
	cmp	r3, #2
	beq	.L530
.LVL861:
	.loc 9 255 0 is_stmt 0 discriminator 1
	cmp	r3, #5
	beq	.L530
.LVL862:
.L529:
.LBE7401:
.LBE7400:
	.loc 8 202 0 is_stmt 1
	mov	r0, r4
	bl	_ZN16btCollisionWorld16updateSingleAabbEP17btCollisionObject
.LVL863:
.L530:
.LBE7399:
	.loc 8 195 0
	add	r5, r5, #1
.LVL864:
.L533:
	.loc 8 195 0 is_stmt 0 discriminator 1
	ldr	r3, [r4, #8]
	cmp	r5, r3
	blt	.L534
.LBE7398:
.LBB7404:
.LBB7405:
.LBB7406:
	.loc 14 186 0 is_stmt 1
	bl	_ZN15CProfileManager12Stop_ProfileEv
.LBE7406:
.LBE7405:
.LBE7404:
.LBE7394:
	.loc 8 205 0
	@ sp needed for prologue
.LVL865:
.LVL866:
	pop	{r3, r4, r5, pc}
.L537:
	.align	2
.L536:
	.word	.LC7-(.LPIC118+4)
	.cfi_endproc
.LFE1495:
	.fnend
	.size	_ZN16btCollisionWorld11updateAabbsEv, .-_ZN16btCollisionWorld11updateAabbsEv
	.section	.text._ZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEf,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEf
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEf, %function
_ZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEf:
	.fnstart
.LFB1551:
	.loc 8 574 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI106:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL867:
	ldr	r4, .L608
.LBB7407:
.LBB7408:
.LBB7409:
	.loc 13 40 0
	ldr	r5, [r3, #4]
.LBE7409:
.LBE7408:
.LBE7407:
	.loc 8 574 0
	mov	r7, r3
	.pad #844
	add	sp, sp, r4
.LCFI107:
	.cfi_def_cfa_offset 864
	.loc 8 574 0
	ldr	r4, .L608+4
	str	r0, [sp, #16]
	str	r1, [sp, #28]
.LPIC119:
	add	r4, pc
	str	r4, [sp, #24]
.LBB7643:
.LBB7410:
.LBB7411:
	.loc 13 38 0
	ldr	r4, [r3, #12]
.LBE7411:
.LBE7410:
.LBB7413:
.LBB7414:
.LBB7415:
.LBB7416:
	.loc 29 111 0
	ldr	r3, [r5, #4]
.LVL868:
.LBE7416:
.LBE7415:
.LBE7414:
.LBE7413:
.LBE7643:
	.loc 8 574 0
	str	r2, [sp, #20]
	ldr	r6, [sp, #864]
.LBB7644:
.LBB7641:
.LBB7412:
	.loc 13 38 0
	str	r4, [sp, #12]
.LVL869:
.LBE7412:
.LBE7641:
.LBB7642:
	.loc 8 578 0
	cmp	r3, #19
	bgt	.L539
.LVL870:
.LBB7417:
.LBB7418:
.LBB7419:
.LBB7420:
	.loc 6 46 0
	ldr	r4, [sp, #24]
	ldr	r3, .L608+8
	mov	r0, #0
.LVL871:
.LBE7420:
.LBE7419:
.LBE7418:
.LBB7425:
.LBB7426:
.LBB7427:
.LBB7428:
.LBB7429:
.LBB7430:
.LBB7431:
.LBB7432:
.LBB7433:
	.file 38 "jni/../../../bullet4droid/jni/src/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.h"
	.loc 38 40 0
	mov	r1, #166
.LVL872:
.LBE7433:
.LBE7432:
.LBE7431:
.LBE7430:
.LBE7429:
.LBE7428:
.LBE7427:
.LBE7426:
.LBE7425:
.LBB7446:
.LBB7423:
.LBB7421:
	.loc 6 46 0
	ldr	r3, [r4, r3]
	str	r0, [sp, #472]
.LBE7421:
.LBE7423:
.LBE7446:
	.loc 8 582 0
	ldr	r4, [sp, #868]
.LBB7447:
.LBB7424:
.LBB7422:
	.loc 6 46 0
	add	r3, r3, #8
	str	r3, [sp, #304]
.LVL873:
.LBE7422:
.LBE7424:
.LBE7447:
.LBB7448:
.LBB7443:
.LBB7440:
	.loc 38 136 0 discriminator 9
	ldr	r0, .L608+12
.LBE7440:
.LBE7443:
.LBE7448:
	.loc 8 583 0
	ldr	r3, [r6, #4]
	.loc 8 582 0
	str	r4, [sp, #476]
.LBB7449:
.LBB7444:
.LBB7441:
	.loc 38 136 0 discriminator 9
	str	r0, [sp, #788]
.LBE7441:
.LBE7444:
.LBE7449:
	.loc 8 583 0
	str	r3, [sp, #468]
.LVL874:
.LBB7450:
.LBB7445:
.LBB7442:
	.loc 38 136 0 discriminator 9
	add	r4, sp, #480
.LBB7439:
.LBB7438:
.LBB7437:
.LBB7436:
.LBB7435:
.LBB7434:
	.loc 38 40 0
	lsl	r1, r1, #1
	ldrb	r2, [r4, r1]
.LVL875:
	.loc 38 41 0
	mov	r3, #1
	bic	r2, r3
	.loc 38 43 0
	mov	r3, #241
	and	r3, r2
	strb	r3, [r4, r1]
.LVL876:
.LBE7434:
.LBE7435:
.LBE7436:
.LBE7437:
.LBE7438:
.LBE7439:
.LBE7442:
.LBE7445:
.LBE7450:
.LBB7451:
.LBB7452:
.LBB7453:
	.file 39 "jni/../../../bullet4droid/jni/src/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.h"
	.loc 39 29 0
	ldr	r0, [sp, #24]
	ldr	r3, .L608+16
.LBE7453:
.LBE7452:
.LBE7451:
	.loc 8 589 0
	ldr	r1, [sp, #16]
	mov	r2, r5
.LBB7458:
.LBB7456:
.LBB7454:
	.loc 39 29 0
	ldr	r3, [r0, r3]
.LBE7454:
.LBE7456:
.LBE7458:
	.loc 8 589 0
	add	r0, sp, #120
.LBB7459:
.LBB7457:
.LBB7455:
	.loc 39 29 0
	add	r3, r3, #8
	str	r3, [sp, #104]
.LBE7455:
.LBE7457:
.LBE7459:
	.loc 8 589 0
	add	r3, sp, #104
	str	r3, [sp]
	mov	r3, r4
	bl	_ZN27btContinuousConvexCollisionC1EPK13btConvexShapeS2_P22btVoronoiSimplexSolverP30btConvexPenetrationDepthSolver
.LVL877:
.LBB7460:
	.loc 8 597 0
	ldr	r4, [sp, #12]
	add	r3, sp, #304
	str	r3, [sp, #4]
	ldr	r3, [sp, #120]
	str	r4, [sp]
	add	r0, sp, #120
.LVL878:
	ldr	r4, [r3, #8]
	ldr	r1, [sp, #28]
	ldr	r2, [sp, #20]
	ldr	r3, [sp, #12]
	blx	r4
.LVL879:
	cmp	r0, #0
	beq	.L559
.LVL880:
.LBB7461:
.LBB7462:
.LBB7463:
	.loc 8 600 0
	add	r4, sp, #436
	.loc 15 258 0
	mov	r1, r4
	mov	r0, r4
	bl	_ZNK9btVector33dotERKS_
.LBE7463:
.LBE7462:
	.loc 8 600 0
	ldr	r1, .L608+12
	bl	__aeabi_fcmpgt
	cmp	r0, #0
	beq	.L559
.LBB7464:
	.loc 8 602 0
	ldr	r0, [sp, #468]
	ldr	r1, [r6, #4]
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L559
.LBB7465:
	.loc 8 604 0
	mov	r0, r4
	bl	_ZN9btVector39normalizeEv
.LVL881:
.LBB7466:
.LBB7467:
.LBB7468:
	.loc 4 321 0
	ldr	r3, [r7, #8]
	mov	r5, #0
.LVL882:
	str	r5, [sp, #244]
	str	r3, [sp, #240]
	add	r3, sp, #248
.LBE7468:
.LBE7467:
.LBE7466:
	.loc 8 612 0
	ldr	r2, [sp, #468]
.LVL883:
.LBB7475:
.LBB7472:
.LBB7469:
	.loc 4 321 0
	ldmia	r4!, {r0, r1, r5}
	stmia	r3!, {r0, r1, r5}
	ldr	r1, [r4]
	str	r1, [r3]
	add	r1, sp, #452
	add	r3, sp, #264
	ldmia	r1!, {r0, r4, r5}
	stmia	r3!, {r0, r4, r5}
	ldr	r1, [r1]
.LBE7469:
.LBE7472:
.LBE7475:
	.loc 8 615 0
	mov	r0, r6
.LBB7476:
.LBB7473:
.LBB7470:
	.loc 4 321 0
	str	r1, [r3]
.LBE7470:
.LBE7473:
.LBE7476:
	.loc 8 615 0
	ldr	r3, [r6]
.LBB7477:
.LBB7474:
.LBB7471:
	.loc 4 321 0
	str	r2, [sp, #280]
.LVL884:
.LBE7471:
.LBE7474:
.LBE7477:
	.loc 8 615 0
	add	r1, sp, #240
	ldr	r3, [r3, #12]
	mov	r2, #1
	blx	r3
.LVL885:
.L559:
.LBE7465:
.LBE7464:
.LBE7461:
.LBE7460:
.LBB7478:
.LBB7479:
.LBB7480:
	.file 40 "jni/../../../bullet4droid/jni/src/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.h"
	.loc 40 30 0
	ldr	r3, .L608+20
	ldr	r4, [sp, #24]
	add	r0, sp, #120
.LVL886:
	ldr	r3, [r4, r3]
	add	r3, r3, #8
	str	r3, [sp, #120]
	b	.L607
.LVL887:
.L539:
.LBE7480:
.LBE7479:
.LBE7478:
.LBE7417:
.LBB7481:
.LBB7482:
.LBB7483:
.LBB7484:
	.loc 35 152 0
	mov	r2, r3
	sub	r2, r2, #21
.LBE7484:
.LBE7483:
.LBE7482:
	.loc 8 621 0
	cmp	r2, #8
	bls	.LCB11286
	b	.L564	@long jump
.LCB11286:
.LVL888:
.LBB7485:
	.loc 8 623 0
	cmp	r3, #21
	bne	.L565
.LVL889:
.LBB7486:
	.loc 8 627 0
	add	r0, sp, #240
	ldr	r1, [sp, #12]
	bl	_ZNK11btTransform7inverseEv
.LVL890:
.LBB7487:
.LBB7488:
	.loc 8 628 0
	ldr	r2, [sp, #28]
	.loc 23 102 0
	add	r0, sp, #72
	add	r1, sp, #240
.LVL891:
	.loc 8 628 0
	add	r2, r2, #48
	.loc 23 102 0
	bl	_ZNK11btTransformclERK9btVector3
.LVL892:
.LBE7488:
.LBE7487:
.LBB7489:
.LBB7490:
	.loc 8 629 0
	ldr	r2, [sp, #20]
	.loc 23 102 0
	add	r0, sp, #88
	add	r1, sp, #240
.LVL893:
	.loc 8 629 0
	add	r2, r2, #48
	.loc 23 102 0
	bl	_ZNK11btTransformclERK9btVector3
.LVL894:
.LBE7490:
.LBE7489:
	.loc 8 631 0
	ldr	r2, [sp, #20]
	add	r0, sp, #144
	add	r1, sp, #240
.LVL895:
	bl	_ZmlRK11btMatrix3x3S1_
.LVL896:
.LBB7491:
.LBB7492:
.LBB7493:
	.loc 23 60 0
	add	r1, sp, #144
.LVL897:
	add	r0, sp, #304
.LVL898:
	bl	_ZN11btMatrix3x3C1ERKS_
.LVL899:
	mov	r3, #0
	str	r3, [sp, #352]
	str	r3, [sp, #356]
	str	r3, [sp, #360]
	str	r3, [sp, #364]
.LVL900:
.LBE7493:
.LBE7492:
.LBE7491:
.LBB7494:
.LBB7495:
.LBB7496:
	.loc 8 642 0
	ldr	r3, [r5]
	.loc 8 645 0
	mov	r0, r5
.LBE7496:
.LBE7495:
.LBE7494:
.LBB7505:
.LBB7506:
	.loc 13 39 0
	ldr	r4, [r7, #8]
.LVL901:
.LBE7506:
.LBE7505:
.LBB7507:
.LBB7501:
.LBB7497:
	.loc 8 645 0
	ldr	r3, [r3, #48]
	blx	r3
.LVL902:
	ldr	r1, [sp, #12]
	str	r0, [sp, #4]
	ldr	r2, [sp, #28]
	str	r1, [sp]
	ldr	r3, [sp, #20]
	ldr	r1, [sp, #16]
	add	r0, sp, #480
.LVL903:
	bl	_ZN28btTriangleConvexcastCallbackC2EPK13btConvexShapeRK11btTransformS5_S5_f
.LVL904:
	ldr	r3, .L608+24
	str	r4, [sp, #696]
.LBE7497:
.LBE7501:
.LBE7507:
	.loc 8 677 0
	ldr	r4, [sp, #868]
.LVL905:
.LBB7508:
.LBB7502:
.LBB7498:
	.loc 8 645 0
.LPIC120:
	add	r3, pc
	add	r3, r3, #96
	str	r3, [sp, #480]
.LBE7498:
.LBE7502:
.LBE7508:
	.loc 8 677 0
	str	r4, [sp, #688]
.LVL906:
	.loc 8 676 0
	ldr	r3, [r6, #4]
	.loc 8 679 0
	ldr	r4, [sp, #16]
.LBB7509:
.LBB7503:
.LBB7499:
	.loc 8 645 0
	str	r6, [sp, #692]
.LBE7499:
.LBE7503:
.LBE7509:
	.loc 8 676 0
	str	r3, [sp, #680]
	.loc 8 679 0
	ldr	r3, [r4]
.LBB7510:
.LBB7504:
.LBB7500:
	.loc 8 645 0
	str	r5, [sp, #700]
.LBE7500:
.LBE7504:
.LBE7510:
	.loc 8 679 0
	add	r6, sp, #104
.LVL907:
	add	r7, sp, #120
.LVL908:
	ldr	r4, [r3, #8]
	ldr	r0, [sp, #16]
	add	r1, sp, #304
.LVL909:
	mov	r2, r6
	mov	r3, r7
	blx	r4
.LVL910:
	.loc 8 680 0
	mov	r0, r5
	add	r1, sp, #480
.LVL911:
	add	r2, sp, #72
	add	r3, sp, #88
	str	r6, [sp]
	str	r7, [sp, #4]
	bl	_ZN22btBvhTriangleMeshShape17performConvexcastEP18btTriangleCallbackRK9btVector3S4_S4_S4_
.LVL912:
	add	r0, sp, #480
.LVL913:
	bl	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD1Ev
.LVL914:
	b	.L538
.LVL915:
.L565:
.LBE7486:
.LBB7511:
	.loc 8 683 0
	cmp	r3, #28
	bne	.L571
.LVL916:
.LBB7512:
.LBB7513:
.LBB7514:
.LBB7515:
	.loc 6 46 0
	ldr	r4, [sp, #24]
	ldr	r3, .L608+8
.LVL917:
	mov	r0, #0
.LBE7515:
.LBE7514:
.LBE7513:
	.loc 8 689 0
	mov	r2, r5
.LBB7520:
.LBB7518:
.LBB7516:
	.loc 6 46 0
	ldr	r3, [r4, r3]
.LBE7516:
.LBE7518:
.LBE7520:
	.loc 8 686 0
	ldr	r4, [sp, #868]
.LBB7521:
.LBB7519:
.LBB7517:
	.loc 6 46 0
	str	r0, [sp, #648]
	add	r3, r3, #8
	str	r3, [sp, #480]
.LVL918:
.LBE7517:
.LBE7519:
.LBE7521:
	.loc 8 687 0
	ldr	r3, [r6, #4]
	.loc 8 689 0
	ldr	r1, [sp, #16]
	add	r0, sp, #240
	.loc 8 686 0
	str	r4, [sp, #652]
	.loc 8 687 0
	str	r3, [sp, #644]
.LVL919:
	.loc 8 689 0
	bl	_ZN27btContinuousConvexCollisionC1EPK13btConvexShapePK18btStaticPlaneShape
.LVL920:
.LBB7522:
	.loc 8 692 0
	ldr	r5, [sp, #12]
.LVL921:
	add	r3, sp, #480
.LVL922:
	str	r3, [sp, #4]
	ldr	r3, [sp, #240]
.LVL923:
	str	r5, [sp]
	add	r0, sp, #240
.LVL924:
	ldr	r4, [r3, #8]
	ldr	r1, [sp, #28]
	ldr	r2, [sp, #20]
	mov	r3, r5
	blx	r4
.LVL925:
	cmp	r0, #0
	beq	.L581
.LVL926:
.LBB7523:
.LBB7524:
.LBB7525:
	.loc 8 695 0
	add	r4, sp, #612
	.loc 15 258 0
	mov	r1, r4
	mov	r0, r4
	bl	_ZNK9btVector33dotERKS_
.LBE7525:
.LBE7524:
	.loc 8 695 0
	ldr	r1, .L608+12
	bl	__aeabi_fcmpgt
	cmp	r0, #0
	beq	.L581
.LBB7526:
	.loc 8 697 0
	ldr	r0, [sp, #644]
	ldr	r1, [r6, #4]
	bl	__aeabi_fcmplt
	cmp	r0, #0
	beq	.L581
.LBB7527:
	.loc 8 699 0
	mov	r0, r4
	bl	_ZN9btVector39normalizeEv
.LVL927:
.LBB7528:
.LBB7529:
.LBB7530:
	.loc 4 321 0
	ldr	r3, [r7, #8]
	mov	r0, #0
	str	r0, [sp, #308]
	str	r3, [sp, #304]
	add	r3, sp, #312
.LBE7530:
.LBE7529:
.LBE7528:
	.loc 8 707 0
	ldr	r1, [sp, #644]
.LVL928:
.LBB7537:
.LBB7534:
.LBB7531:
	.loc 4 321 0
	ldmia	r4!, {r0, r2, r5}
	stmia	r3!, {r0, r2, r5}
	ldr	r2, [r4]
	str	r2, [r3]
	add	r2, sp, #628
	add	r3, sp, #328
	ldmia	r2!, {r0, r4, r5}
	stmia	r3!, {r0, r4, r5}
	ldr	r2, [r2]
.LBE7531:
.LBE7534:
.LBE7537:
	.loc 8 710 0
	mov	r0, r6
.LBB7538:
.LBB7535:
.LBB7532:
	.loc 4 321 0
	str	r2, [r3]
.LBE7532:
.LBE7535:
.LBE7538:
	.loc 8 710 0
	ldr	r3, [r6]
.LBB7539:
.LBB7536:
.LBB7533:
	.loc 4 321 0
	str	r1, [sp, #344]
.LVL929:
.LBE7533:
.LBE7536:
.LBE7539:
	.loc 8 710 0
	mov	r2, #1
	ldr	r3, [r3, #12]
	add	r1, sp, #304
.LVL930:
	blx	r3
.LVL931:
.L581:
.LBE7527:
.LBE7526:
.LBE7523:
.LBE7522:
.LBB7540:
.LBB7541:
.LBB7542:
	.loc 40 30 0
	ldr	r3, .L608+20
	ldr	r4, [sp, #24]
	add	r0, sp, #240
.LVL932:
	ldr	r3, [r4, r3]
	add	r3, r3, #8
	str	r3, [sp, #240]
.LVL933:
.L607:
	bl	_ZN12btConvexCastD2Ev
	b	.L538
.LVL934:
.L571:
.LBE7542:
.LBE7541:
.LBE7540:
.LBE7512:
.LBB7543:
	.loc 8 719 0
	add	r0, sp, #240
	ldr	r1, [sp, #12]
	bl	_ZNK11btTransform7inverseEv
.LVL935:
.LBB7544:
.LBB7545:
	.loc 8 720 0
	ldr	r2, [sp, #28]
	.loc 23 102 0
	add	r0, sp, #40
	add	r1, sp, #240
.LVL936:
	.loc 8 720 0
	add	r2, r2, #48
	.loc 23 102 0
	bl	_ZNK11btTransformclERK9btVector3
.LVL937:
.LBE7545:
.LBE7544:
.LBB7546:
.LBB7547:
	.loc 8 721 0
	ldr	r2, [sp, #20]
	.loc 23 102 0
	add	r0, sp, #56
	add	r1, sp, #240
.LVL938:
	.loc 8 721 0
	add	r2, r2, #48
	.loc 23 102 0
	bl	_ZNK11btTransformclERK9btVector3
.LVL939:
.LBE7547:
.LBE7546:
	.loc 8 723 0
	ldr	r2, [sp, #20]
	add	r0, sp, #192
	add	r1, sp, #240
.LVL940:
	bl	_ZmlRK11btMatrix3x3S1_
.LVL941:
.LBB7548:
.LBB7549:
.LBB7550:
	.loc 23 60 0
	add	r1, sp, #192
.LVL942:
	add	r0, sp, #304
.LVL943:
	bl	_ZN11btMatrix3x3C1ERKS_
.LVL944:
	mov	r3, #0
	str	r3, [sp, #352]
	str	r3, [sp, #356]
	str	r3, [sp, #360]
	str	r3, [sp, #364]
.LVL945:
.LBE7550:
.LBE7549:
.LBE7548:
.LBB7551:
.LBB7552:
.LBB7553:
	.loc 8 734 0
	ldr	r3, [r5]
	.loc 8 737 0
	mov	r0, r5
.LBE7553:
.LBE7552:
.LBE7551:
.LBB7562:
.LBB7563:
	.loc 13 39 0
	ldr	r4, [r7, #8]
.LVL946:
.LBE7563:
.LBE7562:
.LBB7564:
.LBB7558:
.LBB7554:
	.loc 8 737 0
	ldr	r3, [r3, #48]
	blx	r3
.LVL947:
	ldr	r1, [sp, #12]
	str	r0, [sp, #4]
	ldr	r2, [sp, #28]
	str	r1, [sp]
	ldr	r3, [sp, #20]
	ldr	r1, [sp, #16]
	add	r0, sp, #480
.LVL948:
	bl	_ZN28btTriangleConvexcastCallbackC2EPK13btConvexShapeRK11btTransformS5_S5_f
.LVL949:
	ldr	r3, .L608+28
	str	r4, [sp, #696]
.LBE7554:
.LBE7558:
.LBE7564:
	.loc 8 768 0
	ldr	r4, [sp, #868]
.LVL950:
.LBB7565:
.LBB7559:
.LBB7555:
	.loc 8 737 0
.LPIC121:
	add	r3, pc
	add	r3, r3, #120
	str	r3, [sp, #480]
.LBE7555:
.LBE7559:
.LBE7565:
	.loc 8 768 0
	str	r4, [sp, #688]
.LVL951:
	.loc 8 767 0
	ldr	r3, [r6, #4]
	.loc 8 770 0
	ldr	r4, [sp, #16]
.LBB7566:
.LBB7560:
.LBB7556:
	.loc 8 737 0
	str	r6, [sp, #692]
.LBE7556:
.LBE7560:
.LBE7566:
	.loc 8 767 0
	str	r3, [sp, #680]
	.loc 8 770 0
	ldr	r3, [r4]
.LBB7567:
.LBB7561:
.LBB7557:
	.loc 8 737 0
	str	r5, [sp, #700]
.LBE7557:
.LBE7561:
.LBE7567:
	.loc 8 770 0
	ldr	r0, [sp, #16]
	ldr	r4, [r3, #8]
	add	r1, sp, #304
.LVL952:
	add	r3, sp, #88
.LVL953:
	add	r2, sp, #72
.LVL954:
	blx	r4
.LVL955:
	.loc 8 772 0
	add	r1, sp, #40
	mov	r2, #16
	add	r0, sp, #104
	bl	memcpy
	.loc 8 773 0
	add	r0, sp, #104
	add	r1, sp, #56
	bl	_ZN9btVector36setMinERKS_
	.loc 8 774 0
	mov	r2, #16
	add	r1, sp, #40
	add	r0, sp, #120
	bl	memcpy
	.loc 8 775 0
	add	r0, sp, #120
	add	r1, sp, #56
	bl	_ZN9btVector36setMaxERKS_
	.loc 8 776 0
	add	r1, sp, #72
.LVL956:
	add	r0, sp, #104
	bl	_ZN9btVector3pLERKS_
.LVL957:
	.loc 8 777 0
	add	r1, sp, #88
.LVL958:
	add	r0, sp, #120
	bl	_ZN9btVector3pLERKS_
.LVL959:
	.loc 8 778 0
	ldr	r3, [r5]
	mov	r0, r5
	add	r1, sp, #480
.LVL960:
	ldr	r4, [r3, #64]
	add	r2, sp, #104
	add	r3, sp, #120
	blx	r4
.LVL961:
	add	r0, sp, #480
.LVL962:
	bl	_ZZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEfEN32BridgeTriangleConvexcastCallbackD1E_0v
.LVL963:
	b	.L538
.LVL964:
.L564:
.LBE7543:
.LBE7511:
.LBE7485:
.LBB7568:
	.loc 8 783 0
	cmp	r3, #31
	bne	.L538
.LVL965:
.LBB7569:
.LBB7570:
.LBB7571:
.LBB7572:
	.loc 14 181 0
	ldr	r0, .L608+32
	.loc 8 788 0
	mov	r4, #0
	.loc 14 181 0
.LPIC122:
	add	r0, pc
	bl	_ZN15CProfileManager13Start_ProfileEPKc
.LVL966:
.LBE7572:
.LBE7571:
.LBE7570:
.LBB7575:
.LBB7576:
.LBB7577:
.LBB7578:
.LBB7579:
	.loc 8 799 0
	ldr	r0, .L608+36
.LPIC123:
	add	r0, pc
	str	r0, [sp, #36]
	b	.L590
.L609:
	.align	2
.L608:
	.word	-844
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC119+4)
	.word	_ZTVN12btConvexCast10CastResultE(GOT)
	.word	953267991
	.word	_ZTV30btGjkEpaPenetrationDepthSolver(GOT)
	.word	_ZTV27btContinuousConvexCollision(GOT)
	.word	.LANCHOR1-(.LPIC120+4)
	.word	.LANCHOR1-(.LPIC121+4)
	.word	.LC8-(.LPIC122+4)
	.word	.LANCHOR0-(.LPIC123+4)
.LVL967:
.L596:
.LBE7579:
.LBE7578:
.LBE7577:
.LBE7576:
.LBE7575:
.LBB7636:
.LBB7574:
.LBB7573:
	.loc 8 571 0
	mov	r3, #80
	mov	r1, r3
	mul	r1, r4
	str	r1, [sp, #32]
.LBE7573:
.LBE7574:
.LBE7636:
.LBB7637:
.LBB7634:
.LBB7594:
.LBB7595:
.LBB7596:
	.loc 10 172 0
	ldr	r2, [sp, #32]
	ldr	r1, [r5, #24]
.LBE7596:
.LBE7595:
.LBE7594:
	.loc 8 790 0
	add	r0, sp, #304
.LBB7599:
.LBB7598:
.LBB7597:
	.loc 10 172 0
	add	r1, r1, r2
.LBE7597:
.LBE7598:
.LBE7599:
	.loc 8 790 0
	bl	_ZN11btTransformC1ERKS_
.LVL968:
.LBB7600:
.LBB7601:
	.loc 30 96 0
	ldr	r0, [sp, #32]
	ldr	r3, [r5, #24]
.LBE7601:
.LBE7600:
	.loc 8 792 0
	ldr	r1, [sp, #12]
	add	r2, sp, #304
.LBB7604:
.LBB7602:
	.loc 30 96 0
	add	r3, r3, r0
	ldr	r3, [r3, #64]
.LBE7602:
.LBE7604:
	.loc 8 792 0
	add	r0, sp, #480
.LBB7605:
.LBB7603:
	.loc 30 96 0
	str	r3, [sp, #32]
.LBE7603:
.LBE7605:
	.loc 8 792 0
	bl	_ZNK11btTransformmlERKS_
.LVL969:
.LBB7606:
.LBB7590:
.LBB7586:
	.loc 8 799 0
	ldr	r1, [sp, #36]
.LBB7580:
.LBB7581:
.LBB7582:
	.loc 4 342 0
	add	r3, sp, #120
.LVL970:
	mov	r2, #1
	strh	r2, [r3, #8]
.LBE7582:
.LBE7581:
.LBE7580:
	.loc 8 799 0
	add	r1, r1, #32
.LBB7585:
.LBB7584:
.LBB7583:
	.loc 4 342 0
	neg	r2, r2
	strh	r2, [r3, #10]
.LBE7583:
.LBE7584:
.LBE7585:
	.loc 8 799 0
	str	r1, [sp, #120]
	.loc 8 801 0
	ldr	r1, [r6, #4]
.LBE7586:
.LBE7590:
.LBE7606:
.LBB7607:
.LBB7608:
.LBB7609:
	.loc 13 35 0
	ldr	r0, [sp, #32]
	str	r2, [sp, #256]
.LBE7609:
.LBE7608:
.LBE7607:
.LBB7616:
.LBB7591:
.LBB7587:
	.loc 8 801 0
	str	r1, [sp, #124]
.LVL971:
.LBE7587:
.LBE7591:
.LBE7616:
.LBB7617:
.LBB7618:
	.loc 13 39 0
	ldr	r1, [r7, #8]
.LVL972:
.LBE7618:
.LBE7617:
	.loc 8 826 0
	ldr	r2, [sp, #868]
.LBB7619:
.LBB7613:
.LBB7610:
	.loc 13 35 0
	str	r0, [sp, #244]
	str	r1, [sp, #248]
	add	r1, sp, #480
.LVL973:
	str	r1, [sp, #252]
.LBE7610:
.LBE7613:
.LBE7619:
	.loc 8 826 0
	str	r3, [sp]
	str	r2, [sp, #4]
	ldr	r0, [sp, #16]
	add	r3, sp, #240
.LVL974:
	ldr	r1, [sp, #28]
.LVL975:
	ldr	r2, [sp, #20]
.LBB7620:
.LBB7592:
.LBB7588:
	.loc 8 799 0
	str	r4, [sp, #136]
.LBE7588:
.LBE7592:
.LBE7620:
.LBB7621:
.LBB7614:
.LBB7611:
	.loc 13 35 0
	str	r4, [sp, #260]
.LBE7611:
.LBE7614:
.LBE7621:
.LBB7622:
.LBB7593:
.LBB7589:
	.loc 8 799 0
	str	r6, [sp, #132]
.LBE7589:
.LBE7593:
.LBE7622:
.LBB7623:
.LBB7615:
.LBB7612:
	.loc 13 35 0
	str	r7, [sp, #240]
.LBE7612:
.LBE7615:
.LBE7623:
	.loc 8 826 0
	bl	_ZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEf
.LVL976:
.LBB7624:
.LBB7625:
.LBB7626:
.LBB7627:
.LBB7628:
	.loc 4 347 0
	ldr	r3, .L610
	ldr	r0, [sp, #24]
.LBE7628:
.LBE7627:
.LBE7626:
.LBE7625:
.LBE7624:
.LBE7634:
	.loc 8 788 0 discriminator 2
	add	r4, r4, #1
.LVL977:
.LBB7635:
.LBB7633:
.LBB7632:
.LBB7631:
.LBB7630:
.LBB7629:
	.loc 4 347 0
	ldr	r3, [r0, r3]
	add	r3, r3, #8
	str	r3, [sp, #120]
.LVL978:
.L590:
.LBE7629:
.LBE7630:
.LBE7631:
.LBE7632:
.LBE7633:
.LBE7635:
	.loc 8 788 0 discriminator 1
	ldr	r3, [r5, #16]
	cmp	r4, r3
	blt	.L596
.LBE7637:
.LBB7638:
.LBB7639:
.LBB7640:
	.loc 14 186 0
	bl	_ZN15CProfileManager12Stop_ProfileEv
.LVL979:
.L538:
.LBE7640:
.LBE7639:
.LBE7638:
.LBE7569:
.LBE7568:
.LBE7481:
.LBE7642:
.LBE7644:
	.loc 8 832 0
	mov	r3, #211
	lsl	r3, r3, #2
	add	sp, sp, r3
	@ sp needed for prologue
	pop	{r4, r5, r6, r7, pc}
.L611:
	.align	2
.L610:
	.word	_ZTVN16btCollisionWorld20ConvexResultCallbackE(GOT)
	.cfi_endproc
.LFE1551:
	.fnend
	.size	_ZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEf, .-_ZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEf
	.section	.text._ZN16btCollisionWorld17objectQuerySingleEPK13btConvexShapeRK11btTransformS5_P17btCollisionObjectPK16btCollisionShapeS5_RNS_20ConvexResultCallbackEf,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorld17objectQuerySingleEPK13btConvexShapeRK11btTransformS5_P17btCollisionObjectPK16btCollisionShapeS5_RNS_20ConvexResultCallbackEf
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld17objectQuerySingleEPK13btConvexShapeRK11btTransformS5_P17btCollisionObjectPK16btCollisionShapeS5_RNS_20ConvexResultCallbackEf, %function
_ZN16btCollisionWorld17objectQuerySingleEPK13btConvexShapeRK11btTransformS5_P17btCollisionObjectPK16btCollisionShapeS5_RNS_20ConvexResultCallbackEf:
	.fnstart
.LFB1550:
	.loc 8 566 0
	.cfi_startproc
	.save	{r4, lr}
	push	{r4, lr}
.LCFI108:
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL980:
	.pad #32
	sub	sp, sp, #32
.LCFI109:
	.cfi_def_cfa_offset 40
.LVL981:
.LBB7645:
.LBB7646:
.LBB7647:
.LBB7648:
	.loc 13 35 0
	str	r3, [sp, #16]
	ldr	r3, [sp, #44]
.LVL982:
	mov	r4, #0
	str	r4, [sp, #8]
	str	r3, [sp, #20]
	mov	r3, #1
	neg	r3, r3
	str	r3, [sp, #24]
	str	r3, [sp, #28]
.LBE7648:
.LBE7647:
.LBE7646:
	.loc 8 568 0
	ldr	r3, [sp, #48]
.LBB7653:
.LBB7651:
.LBB7649:
	.loc 13 35 0
	ldr	r4, [sp, #40]
.LBE7649:
.LBE7651:
.LBE7653:
	.loc 8 568 0
	str	r3, [sp]
	ldr	r3, [sp, #52]
.LBB7654:
.LBB7652:
.LBB7650:
	.loc 13 35 0
	str	r4, [sp, #12]
.LBE7650:
.LBE7652:
.LBE7654:
	.loc 8 568 0
	str	r3, [sp, #4]
	add	r3, sp, #8
	bl	_ZN16btCollisionWorld25objectQuerySingleInternalEPK13btConvexShapeRK11btTransformS5_PK24btCollisionObjectWrapperRNS_20ConvexResultCallbackEf
.LVL983:
.LBE7645:
	.loc 8 569 0
	add	sp, sp, #32
	@ sp needed for prologue
	pop	{r4, pc}
	.cfi_endproc
.LFE1550:
	.fnend
	.size	_ZN16btCollisionWorld17objectQuerySingleEPK13btConvexShapeRK11btTransformS5_P17btCollisionObjectPK16btCollisionShapeS5_RNS_20ConvexResultCallbackEf, .-_ZN16btCollisionWorld17objectQuerySingleEPK13btConvexShapeRK11btTransformS5_P17btCollisionObjectPK16btCollisionShapeS5_RNS_20ConvexResultCallbackEf
	.global	__aeabi_fcmpeq
	.section	.text._ZN21btSingleSweepCallback7processEPK17btBroadphaseProxy,"axG",%progbits,_ZN21btSingleSweepCallback7processEPK17btBroadphaseProxy,comdat
	.align	1
	.weak	_ZN21btSingleSweepCallback7processEPK17btBroadphaseProxy
	.code	16
	.thumb_func
	.type	_ZN21btSingleSweepCallback7processEPK17btBroadphaseProxy, %function
_ZN21btSingleSweepCallback7processEPK17btBroadphaseProxy:
	.fnstart
.LFB1607:
	.loc 8 966 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI110:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL984:
.LBB7663:
	.loc 8 969 0
	mov	r6, r0
	add	r6, r6, #184
	ldr	r5, [r6]
.LBE7663:
	.loc 8 966 0
	.pad #28
	sub	sp, sp, #28
.LCFI111:
	.cfi_def_cfa_offset 48
	.loc 8 966 0
	mov	r7, r0
	mov	r4, r1
.LBB7664:
	.loc 8 969 0
	ldr	r0, [r5, #4]
.LVL985:
	mov	r1, #0
.LVL986:
	bl	__aeabi_fcmpeq
	.loc 8 970 0
	mov	r3, #0
	str	r3, [sp, #20]
	.loc 8 969 0
	cmp	r0, r3
	bne	.L615
.LVL987:
.LBE7664:
.LBB7665:
.LBB7666:
	.loc 8 972 0
	ldr	r4, [r4]
.LVL988:
	.loc 8 975 0
	ldr	r3, [r5]
	mov	r0, r5
.LBB7667:
.LBB7668:
	.loc 9 309 0
	mov	r2, r4
	add	r2, r2, #188
.LBE7668:
.LBE7667:
	.loc 8 975 0
	ldr	r3, [r3, #8]
	ldr	r1, [r2]
	blx	r3
	mov	r3, #1
	str	r3, [sp, #20]
	cmp	r0, #0
	beq	.L615
.LVL989:
	.loc 8 982 0
	mov	r3, r7
	add	r3, r3, #192
	ldr	r0, [r3]
.LBB7669:
.LBB7670:
	.loc 9 216 0
	mov	r3, r4
	add	r3, r3, #192
.LBE7670:
.LBE7669:
	.loc 8 982 0
	ldr	r3, [r3]
	mov	r1, r7
	mov	r2, r7
	str	r3, [sp]
.LBE7666:
	.loc 8 980 0
	add	r3, r4, #4
.LBB7671:
	.loc 8 982 0
	str	r3, [sp, #4]
	ldr	r3, [r6]
	add	r7, r7, #188
.LVL990:
	add	r1, r1, #36
.LVL991:
	str	r3, [sp, #8]
	ldr	r3, [r7]
	add	r2, r2, #100
.LVL992:
	str	r3, [sp, #12]
	mov	r3, r4
	bl	_ZN16btCollisionWorld17objectQuerySingleEPK13btConvexShapeRK11btTransformS5_P17btCollisionObjectPK16btCollisionShapeS5_RNS_20ConvexResultCallbackEf
.LVL993:
.L615:
.LBE7671:
.LBE7665:
	.loc 8 986 0
	ldr	r0, [sp, #20]
	add	sp, sp, #28
	@ sp needed for prologue
.LVL994:
	pop	{r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE1607:
	.fnend
	.size	_ZN21btSingleSweepCallback7processEPK17btBroadphaseProxy, .-_ZN21btSingleSweepCallback7processEPK17btBroadphaseProxy
	.section	.text._ZN19btSingleRayCallbackC2ERK9btVector3S2_PK16btCollisionWorldRNS3_17RayResultCallbackE,"axG",%progbits,_ZN19btSingleRayCallbackC5ERK9btVector3S2_PK16btCollisionWorldRNS3_17RayResultCallbackE,comdat
	.align	1
	.weak	_ZN19btSingleRayCallbackC2ERK9btVector3S2_PK16btCollisionWorldRNS3_17RayResultCallbackE
	.code	16
	.thumb_func
	.type	_ZN19btSingleRayCallbackC2ERK9btVector3S2_PK16btCollisionWorldRNS3_17RayResultCallbackE, %function
_ZN19btSingleRayCallbackC2ERK9btVector3S2_PK16btCollisionWorldRNS3_17RayResultCallbackE:
	.fnstart
.LFB1596:
	.loc 8 847 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI112:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL995:
	.pad #44
	sub	sp, sp, #44
.LCFI113:
	.cfi_def_cfa_offset 64
	.loc 8 847 0
	str	r2, [sp]
.LBB7672:
.LBB7673:
.LBB7674:
.LBB7675:
	.loc 3 36 0
	ldr	r2, .L639
.LVL996:
.LBE7675:
.LBE7674:
.LBE7673:
	.loc 8 851 0
	mov	r5, r0
.LBE7672:
	.loc 8 847 0
	str	r1, [sp, #4]
.LBB7690:
.LBB7678:
.LBB7677:
.LBB7676:
	.loc 3 36 0
.LPIC125:
	add	r2, pc
.LBE7676:
.LBE7677:
.LBE7678:
	.loc 8 851 0
	ldr	r2, [r2]
	add	r5, r5, #36
.LBE7690:
	.loc 8 847 0
	mov	r4, r0
.LBB7691:
	.loc 8 851 0
	add	r2, r2, #8
	str	r2, [r0]
	mov	r2, r1
.LBE7691:
	.loc 8 847 0
	mov	ip, r3
.LBB7692:
	.loc 8 851 0
	ldmia	r2!, {r0, r1, r3}
	stmia	r5!, {r0, r1, r3}
.LVL997:
	ldr	r2, [r2]
	mov	r6, r4
	add	r6, r6, #52
	str	r2, [r5]
	ldr	r2, [sp]
	mov	r3, ip
	ldmia	r2!, {r0, r1, r7}
	stmia	r6!, {r0, r1, r7}
	ldr	r2, [r2]
.LBB7679:
	.loc 8 853 0
	mov	r0, r4
	add	r0, r0, #68
.LBE7679:
	.loc 8 851 0
	str	r2, [r6]
.LVL998:
	mov	r2, r4
	add	r2, r2, #212
	str	r3, [r2]
	ldr	r2, [sp, #64]
	mov	r3, r4
	add	r3, r3, #216
	str	r2, [r3]
.LBB7688:
	.loc 8 853 0
	bl	_ZN11btTransform11setIdentityEv
.LVL999:
.LBB7680:
.LBB7681:
	.loc 23 152 0
	mov	r7, #36
	mov	r3, r4
	add	r3, r3, #116
	add	r7, r7, r4
	ldmia	r7!, {r0, r1, r2}
	stmia	r3!, {r0, r1, r2}
	ldr	r2, [r5]
.LBE7681:
.LBE7680:
	.loc 8 855 0
	mov	r0, r4
	add	r0, r0, #132
.LBB7683:
.LBB7682:
	.loc 23 152 0
	str	r2, [r3]
.LBE7682:
.LBE7683:
	.loc 8 855 0
	bl	_ZN11btTransform11setIdentityEv
.LVL1000:
.LBB7684:
.LBB7685:
	.loc 23 152 0
	mov	r3, r4
	mov	r2, r4
	add	r3, r3, #180
	add	r2, r2, #52
	ldmia	r2!, {r0, r5, r7}
	stmia	r3!, {r0, r5, r7}
.LVL1001:
	ldr	r2, [r6]
.LBE7685:
.LBE7684:
	.loc 8 858 0
	add	r0, sp, #8
.LBB7687:
.LBB7686:
	.loc 23 152 0
	str	r2, [r3]
.LBE7686:
.LBE7687:
	.loc 8 858 0
	ldr	r1, [sp]
	ldr	r2, [sp, #4]
	bl	_ZmiRK9btVector3S1_
	.loc 8 860 0
	add	r0, sp, #8
	bl	_ZN9btVector39normalizeEv
.LVL1002:
	.loc 8 862 0
	ldr	r5, [sp, #8]
	mov	r1, #0
	add	r0, r5, #0
	bl	__aeabi_fcmpeq
	cmp	r0, #0
	bne	.L636
.LVL1003:
	.loc 8 862 0 is_stmt 0 discriminator 2
	mov	r0, #254
	add	r1, r5, #0
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
	add	r5, r0, #0
	b	.L629
.LVL1004:
.L636:
	.loc 8 862 0 discriminator 1
	ldr	r5, .L639+4
.LVL1005:
.L629:
	.loc 8 863 0 is_stmt 1
	ldr	r6, [sp, #12]
.LVL1006:
	.loc 8 862 0 discriminator 3
	str	r5, [r4, #4]
.LVL1007:
	.loc 8 863 0
	mov	r1, #0
	add	r0, r6, #0
	bl	__aeabi_fcmpeq
	cmp	r0, #0
	bne	.L637
.LVL1008:
	.loc 8 863 0 is_stmt 0 discriminator 2
	mov	r0, #254
	add	r1, r6, #0
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
	add	r6, r0, #0
	b	.L630
.LVL1009:
.L637:
	.loc 8 863 0 discriminator 1
	ldr	r6, .L639+4
.L630:
	.loc 8 864 0 is_stmt 1
	ldr	r7, [sp, #16]
	.loc 8 863 0 discriminator 3
	str	r6, [r4, #8]
.LVL1010:
	.loc 8 864 0
	mov	r1, #0
	add	r0, r7, #0
	bl	__aeabi_fcmpeq
	cmp	r0, #0
	bne	.L638
.LVL1011:
	.loc 8 864 0 is_stmt 0 discriminator 2
	mov	r0, #254
	add	r1, r7, #0
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
	add	r7, r0, #0
	b	.L631
.LVL1012:
.L638:
	.loc 8 864 0 discriminator 1
	ldr	r7, .L639+4
.L631:
	.loc 8 864 0 discriminator 3
	str	r7, [r4, #12]
.LVL1013:
	.loc 8 865 0 is_stmt 1
	add	r0, r5, #0
	mov	r1, #0
	bl	__aeabi_fcmplt
	sub	r3, r0, #1
	sbc	r0, r0, r3
	str	r0, [r4, #20]
.LVL1014:
	.loc 8 866 0
	mov	r1, #0
	add	r0, r6, #0
	bl	__aeabi_fcmplt
	sub	r3, r0, #1
	sbc	r0, r0, r3
	str	r0, [r4, #24]
.LVL1015:
	.loc 8 867 0
	mov	r1, #0
	add	r0, r7, #0
	bl	__aeabi_fcmplt
	.loc 8 869 0
	mov	r1, r4
	.loc 8 867 0
	sub	r3, r0, #1
	sbc	r0, r0, r3
	.loc 8 869 0
	mov	r2, r4
	.loc 8 867 0
	str	r0, [r4, #28]
	.loc 8 869 0
	add	r2, r2, #36
	add	r0, sp, #24
	add	r1, r1, #52
	bl	_ZmiRK9btVector3S1_
	add	r1, sp, #24
	add	r0, sp, #8
.LVL1016:
	bl	_ZNK9btVector33dotERKS_
.LVL1017:
.LBE7688:
.LBE7692:
	.loc 8 871 0
	add	sp, sp, #44
.LVL1018:
.LBB7693:
.LBB7689:
	.loc 8 869 0
	str	r0, [r4, #32]
.LBE7689:
.LBE7693:
	.loc 8 871 0
	@ sp needed for prologue
	mov	r0, r4
.LVL1019:
	pop	{r4, r5, r6, r7, pc}
.L640:
	.align	2
.L639:
	.word	_ZTV19btSingleRayCallback(GOT_PREL)+(.-(.LPIC125+4))
	.word	1566444395
	.cfi_endproc
.LFE1596:
	.fnend
	.size	_ZN19btSingleRayCallbackC2ERK9btVector3S2_PK16btCollisionWorldRNS3_17RayResultCallbackE, .-_ZN19btSingleRayCallbackC2ERK9btVector3S2_PK16btCollisionWorldRNS3_17RayResultCallbackE
	.section	.text._ZNK16btCollisionWorld7rayTestERK9btVector3S2_RNS_17RayResultCallbackE,"ax",%progbits
	.align	1
	.global	_ZNK16btCollisionWorld7rayTestERK9btVector3S2_RNS_17RayResultCallbackE
	.code	16
	.thumb_func
	.type	_ZNK16btCollisionWorld7rayTestERK9btVector3S2_RNS_17RayResultCallbackE, %function
_ZNK16btCollisionWorld7rayTestERK9btVector3S2_RNS_17RayResultCallbackE:
	.fnstart
.LFB1599:
	.loc 8 914 0
	.cfi_startproc
	.save	{r4, r5, r6, lr}
	push	{r4, r5, r6, lr}
.LCFI114:
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
.LVL1020:
	.pad #264
	sub	sp, sp, #264
.LCFI115:
	.cfi_def_cfa_offset 280
	.loc 8 914 0
	mov	r4, r0
.LBB7694:
	.loc 8 918 0
	str	r3, [sp]
	add	r0, sp, #44
.LVL1021:
	mov	r3, r4
.LVL1022:
.LBE7694:
	.loc 8 914 0
	mov	r5, r1
	mov	r6, r2
.LBB7707:
	.loc 8 918 0
	bl	_ZN19btSingleRayCallbackC1ERK9btVector3S2_PK16btCollisionWorldRNS3_17RayResultCallbackE
.LVL1023:
	.loc 8 921 0
	ldr	r0, [r4, #68]
.LBB7695:
.LBB7696:
.LBB7697:
	.loc 15 132 0
	add	r1, sp, #12
.LBE7697:
.LBE7696:
.LBE7695:
.LBB7700:
.LBB7701:
.LBB7702:
	add	r2, sp, #28
.LBE7702:
.LBE7701:
.LBE7700:
	.loc 8 921 0
	ldr	r3, [r0]
	ldr	r4, [r3, #24]
.LVL1024:
.LBB7705:
.LBB7699:
.LBB7698:
	.loc 15 132 0
	mov	r3, #0
	str	r3, [sp, #12]
	.loc 15 133 0
	str	r3, [sp, #16]
	.loc 15 134 0
	str	r3, [sp, #20]
	.loc 15 135 0
	str	r3, [sp, #24]
.LVL1025:
.LBE7698:
.LBE7699:
.LBE7705:
.LBB7706:
.LBB7704:
.LBB7703:
	.loc 15 132 0
	str	r3, [sp, #28]
	.loc 15 133 0
	str	r3, [sp, #32]
	.loc 15 134 0
	str	r3, [sp, #36]
	.loc 15 135 0
	str	r3, [sp, #40]
.LBE7703:
.LBE7704:
.LBE7706:
	.loc 8 921 0
	str	r1, [sp]
	str	r2, [sp, #4]
	mov	r1, r5
.LVL1026:
	mov	r2, r6
.LVL1027:
	add	r3, sp, #44
	blx	r4
.LVL1028:
.LBE7707:
	.loc 8 929 0
	add	sp, sp, #264
	@ sp needed for prologue
.LVL1029:
.LVL1030:
	pop	{r4, r5, r6, pc}
	.cfi_endproc
.LFE1599:
	.fnend
	.size	_ZNK16btCollisionWorld7rayTestERK9btVector3S2_RNS_17RayResultCallbackE, .-_ZNK16btCollisionWorld7rayTestERK9btVector3S2_RNS_17RayResultCallbackE
	.section	.text._ZN21btSingleSweepCallbackC2EPK13btConvexShapeRK11btTransformS5_PK16btCollisionWorldRNS6_20ConvexResultCallbackEf,"axG",%progbits,_ZN21btSingleSweepCallbackC5EPK13btConvexShapeRK11btTransformS5_PK16btCollisionWorldRNS6_20ConvexResultCallbackEf,comdat
	.align	1
	.weak	_ZN21btSingleSweepCallbackC2EPK13btConvexShapeRK11btTransformS5_PK16btCollisionWorldRNS6_20ConvexResultCallbackEf
	.code	16
	.thumb_func
	.type	_ZN21btSingleSweepCallbackC2EPK13btConvexShapeRK11btTransformS5_PK16btCollisionWorldRNS6_20ConvexResultCallbackEf, %function
_ZN21btSingleSweepCallbackC2EPK13btConvexShapeRK11btTransformS5_PK16btCollisionWorldRNS6_20ConvexResultCallbackEf:
	.fnstart
.LFB1605:
	.loc 8 944 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI116:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL1031:
	mov	r5, r3
.LBB7708:
.LBB7709:
.LBB7710:
.LBB7711:
	.loc 3 36 0
	ldr	r3, .L663
.LVL1032:
.LBE7711:
.LBE7710:
.LBE7709:
.LBE7708:
	.loc 8 944 0
	.pad #44
	sub	sp, sp, #44
.LCFI117:
	.cfi_def_cfa_offset 64
	.loc 8 944 0
	mov	r4, r0
.LBB7745:
.LBB7714:
.LBB7713:
.LBB7712:
	.loc 3 36 0
.LPIC129:
	add	r3, pc
.LBE7712:
.LBE7713:
.LBE7714:
	.loc 8 950 0
	ldr	r3, [r3]
.LBE7745:
	.loc 8 944 0
	mov	r6, r1
.LBB7746:
	.loc 8 950 0
	mov	r1, r2
.LVL1033:
	add	r3, r3, #8
	str	r3, [r0]
	add	r0, r0, #36
.LVL1034:
	bl	_ZN11btTransformC1ERKS_
.LVL1035:
	mov	r0, r4
	mov	r1, r5
	add	r0, r0, #100
	bl	_ZN11btTransformC1ERKS_
.LVL1036:
	ldr	r2, [sp, #64]
	mov	r3, r4
	add	r3, r3, #180
	str	r2, [r3]
	ldr	r2, [sp, #68]
.LBB7715:
	.loc 8 952 0
	mov	r1, r4
.LBE7715:
	.loc 8 950 0
	str	r6, [r3, #12]
	str	r2, [r3, #4]
	ldr	r2, [sp, #72]
.LBB7742:
	.loc 8 952 0
	add	r1, r1, #148
	add	r0, sp, #8
.LBE7742:
	.loc 8 950 0
	str	r2, [r3, #8]
.LBB7743:
	.loc 8 952 0
	mov	r2, r4
	add	r2, r2, #84
	bl	_ZmiRK9btVector3S1_
.LVL1037:
.LBB7716:
.LBB7717:
.LBB7718:
.LBB7719:
	.loc 15 258 0
	add	r0, sp, #8
.LVL1038:
	mov	r1, r0
	bl	_ZNK9btVector33dotERKS_
.LVL1039:
.LBE7719:
.LBE7718:
.LBB7720:
.LBB7721:
	.loc 16 382 0
	bl	sqrtf
.LVL1040:
	add	r1, r0, #0
.LVL1041:
.LBE7721:
.LBE7720:
.LBE7717:
.LBB7722:
.LBB7723:
	.loc 15 842 0
	mov	r0, #254
	lsl	r0, r0, #22
	bl	__aeabi_fdiv
.LBB7724:
.LBB7725:
	.loc 15 818 0
	ldr	r1, [sp, #8]
.LBE7725:
.LBE7724:
	.loc 15 842 0
	add	r5, r0, #0
.LVL1042:
.LBB7737:
.LBB7735:
	.loc 15 818 0
	bl	__aeabi_fmul
	ldr	r1, [sp, #12]
	add	r6, r0, #0
.LVL1043:
	add	r0, r5, #0
	bl	__aeabi_fmul
	ldr	r1, [sp, #16]
	add	r7, r0, #0
	add	r0, r5, #0
	bl	__aeabi_fmul
.LBB7726:
.LBB7727:
.LBB7728:
	.loc 15 135 0
	mov	r1, #0
.LBE7728:
.LBE7727:
.LBE7726:
	.loc 15 818 0
	str	r0, [sp, #4]
.LVL1044:
.LBB7733:
.LBB7731:
.LBB7729:
	.loc 15 134 0
	str	r0, [sp, #32]
.LBE7729:
.LBE7731:
.LBE7733:
.LBE7735:
.LBE7737:
.LBE7723:
.LBE7722:
.LBE7716:
	.loc 8 955 0
	add	r0, r6, #0
.LBB7741:
.LBB7740:
.LBB7739:
.LBB7738:
.LBB7736:
.LBB7734:
.LBB7732:
.LBB7730:
	.loc 15 132 0
	str	r6, [sp, #24]
	.loc 15 133 0
	str	r7, [sp, #28]
	.loc 15 135 0
	str	r1, [sp, #36]
.LVL1045:
.LBE7730:
.LBE7732:
.LBE7734:
.LBE7736:
.LBE7738:
.LBE7739:
.LBE7740:
.LBE7741:
	.loc 8 955 0
	bl	__aeabi_fcmpeq
	cmp	r0, #0
	bne	.L660
.LVL1046:
	.loc 8 955 0 is_stmt 0 discriminator 2
	mov	r0, #254
	lsl	r0, r0, #22
	add	r1, r6, #0
	bl	__aeabi_fdiv
	str	r0, [sp]
	b	.L653
.LVL1047:
.L660:
	.loc 8 955 0 discriminator 1
	ldr	r3, .L663+4
	str	r3, [sp]
.L653:
	.loc 8 955 0 discriminator 3
	ldr	r3, [sp]
	.loc 8 956 0 is_stmt 1
	add	r0, r7, #0
	mov	r1, #0
	.loc 8 955 0 discriminator 3
	str	r3, [r4, #4]
.LVL1048:
	.loc 8 956 0
	bl	__aeabi_fcmpeq
	cmp	r0, #0
	bne	.L661
.LVL1049:
	.loc 8 956 0 is_stmt 0 discriminator 2
	mov	r0, #254
	lsl	r0, r0, #22
	add	r1, r7, #0
	bl	__aeabi_fdiv
	add	r5, r0, #0
	b	.L654
.LVL1050:
.L661:
	.loc 8 956 0 discriminator 1
	ldr	r5, .L663+4
.L654:
	.loc 8 956 0 discriminator 3
	str	r5, [r4, #8]
.LVL1051:
	.loc 8 957 0 is_stmt 1
	ldr	r0, [sp, #4]
	mov	r1, #0
	bl	__aeabi_fcmpeq
	cmp	r0, #0
	bne	.L662
.LVL1052:
	.loc 8 957 0 is_stmt 0 discriminator 2
	mov	r0, #254
	lsl	r0, r0, #22
	ldr	r1, [sp, #4]
	bl	__aeabi_fdiv
	add	r6, r0, #0
	b	.L655
.LVL1053:
.L662:
	.loc 8 957 0 discriminator 1
	ldr	r6, .L663+4
.L655:
	.loc 8 957 0 discriminator 3
	str	r6, [r4, #12]
.LVL1054:
	.loc 8 958 0 is_stmt 1
	ldr	r0, [sp]
	mov	r1, #0
	bl	__aeabi_fcmplt
	sub	r3, r0, #1
	sbc	r0, r0, r3
	str	r0, [r4, #20]
.LVL1055:
	.loc 8 959 0
	mov	r1, #0
	add	r0, r5, #0
	bl	__aeabi_fcmplt
	sub	r3, r0, #1
	sbc	r0, r0, r3
	str	r0, [r4, #24]
.LVL1056:
	.loc 8 960 0
	mov	r1, #0
	add	r0, r6, #0
	bl	__aeabi_fcmplt
	sub	r3, r0, #1
	sbc	r0, r0, r3
	str	r0, [r4, #28]
	.loc 8 962 0
	add	r1, sp, #8
.LVL1057:
	add	r0, sp, #24
	bl	_ZNK9btVector33dotERKS_
.LVL1058:
.LBE7743:
.LBE7746:
	.loc 8 964 0
	add	sp, sp, #44
.LBB7747:
.LBB7744:
	.loc 8 962 0
	str	r0, [r4, #32]
.LBE7744:
.LBE7747:
	.loc 8 964 0
	@ sp needed for prologue
	mov	r0, r4
.LVL1059:
	pop	{r4, r5, r6, r7, pc}
.L664:
	.align	2
.L663:
	.word	_ZTV21btSingleSweepCallback(GOT_PREL)+(.-(.LPIC129+4))
	.word	1566444395
	.cfi_endproc
.LFE1605:
	.fnend
	.size	_ZN21btSingleSweepCallbackC2EPK13btConvexShapeRK11btTransformS5_PK16btCollisionWorldRNS6_20ConvexResultCallbackEf, .-_ZN21btSingleSweepCallbackC2EPK13btConvexShapeRK11btTransformS5_PK16btCollisionWorldRNS6_20ConvexResultCallbackEf
	.section	.text._ZNK16btCollisionWorld15convexSweepTestEPK13btConvexShapeRK11btTransformS5_RNS_20ConvexResultCallbackEf,"ax",%progbits
	.align	1
	.global	_ZNK16btCollisionWorld15convexSweepTestEPK13btConvexShapeRK11btTransformS5_RNS_20ConvexResultCallbackEf
	.code	16
	.thumb_func
	.type	_ZNK16btCollisionWorld15convexSweepTestEPK13btConvexShapeRK11btTransformS5_RNS_20ConvexResultCallbackEf, %function
_ZNK16btCollisionWorld15convexSweepTestEPK13btConvexShapeRK11btTransformS5_RNS_20ConvexResultCallbackEf:
	.fnstart
.LFB1608:
	.loc 8 992 0
	.cfi_startproc
	.save	{r0, r1, r4, r5, r6, r7, lr}
	push	{r0, r1, r4, r5, r6, r7, lr}
.LCFI118:
	.cfi_def_cfa_offset 28
	.cfi_offset 0, -28
	.cfi_offset 1, -24
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL1060:
	mov	r6, r0
.LBB7748:
.LBB7749:
.LBB7750:
.LBB7751:
	.loc 14 181 0
	ldr	r0, .L687
.LVL1061:
.LBE7751:
.LBE7750:
.LBE7749:
.LBE7748:
	.loc 8 992 0
	.pad #508
	sub	sp, sp, #508
.LCFI119:
	.cfi_def_cfa_offset 536
	.loc 8 992 0
	mov	r4, r2
.LBB7788:
.LBB7756:
.LBB7754:
.LBB7752:
	.loc 14 181 0
.LPIC132:
	add	r0, pc
.LBE7752:
.LBE7754:
.LBE7756:
.LBE7788:
	.loc 8 992 0
	mov	r5, r3
	str	r1, [sp, #20]
.LBB7789:
.LBB7757:
.LBB7755:
.LBB7753:
	.loc 14 181 0
	bl	_ZN15CProfileManager13Start_ProfileEPKc
.LVL1062:
.LBE7753:
.LBE7755:
.LBE7757:
.LBB7758:
.LBB7759:
	.loc 23 71 0
	mov	r1, r4
	add	r0, sp, #124
	bl	_ZN11btMatrix3x3aSERKS_
	.loc 23 72 0
	mov	r2, r4
	add	r3, sp, #172
	add	r2, r2, #48
	ldmia	r2!, {r0, r1, r7}
	stmia	r3!, {r0, r1, r7}
	ldr	r2, [r2]
.LBE7759:
.LBE7758:
.LBB7761:
.LBB7762:
	.loc 23 71 0
	mov	r1, r5
	add	r0, sp, #188
.LBE7762:
.LBE7761:
.LBB7765:
.LBB7760:
	.loc 23 72 0
	str	r2, [r3]
.LVL1063:
.LBE7760:
.LBE7765:
.LBB7766:
.LBB7763:
	.loc 23 71 0
	bl	_ZN11btMatrix3x3aSERKS_
	.loc 23 72 0
	mov	r2, r5
	add	r3, sp, #236
	add	r2, r2, #48
	ldmia	r2!, {r0, r1, r7}
	stmia	r3!, {r0, r1, r7}
	ldr	r2, [r2]
.LBE7763:
.LBE7766:
.LBB7767:
	.loc 8 1008 0
	mov	r7, #254
	lsl	r7, r7, #22
	add	r0, sp, #76
.LBE7767:
.LBB7776:
.LBB7764:
	.loc 23 72 0
	str	r2, [r3]
.LVL1064:
.LBE7764:
.LBE7776:
.LBB7777:
	.loc 8 1008 0
	add	r1, sp, #188
	add	r2, r7, #0
	str	r0, [sp]
	add	r3, sp, #60
	add	r0, sp, #124
.LVL1065:
	bl	_ZN15btTransformUtil17calculateVelocityERK11btTransformS2_fR9btVector3S4_
.LVL1066:
.LBB7768:
.LBB7769:
	.loc 15 632 0
	mov	r3, #0
.LBE7769:
.LBE7768:
	.loc 8 1012 0
	add	r0, sp, #252
.LBB7771:
.LBB7770:
	.loc 15 632 0
	str	r3, [sp, #92]
	.loc 15 633 0
	str	r3, [sp, #96]
	.loc 15 634 0
	str	r3, [sp, #100]
	.loc 15 635 0
	str	r3, [sp, #104]
.LVL1067:
.LBE7770:
.LBE7771:
	.loc 8 1012 0
	bl	_ZN11btTransform11setIdentityEv
.LVL1068:
.LBB7772:
.LBB7773:
	.loc 23 124 0
	add	r0, sp, #124
	add	r1, sp, #108
	bl	_ZNK11btMatrix3x311getRotationER12btQuaternion
.LVL1069:
.LBE7773:
.LBE7772:
.LBB7774:
.LBB7775:
	.loc 23 167 0
	add	r0, sp, #252
.LVL1070:
	add	r1, sp, #108
	bl	_ZN11btMatrix3x311setRotationERK12btQuaternion
.LVL1071:
.LBE7775:
.LBE7774:
	.loc 8 1014 0
	add	r1, sp, #44
	str	r7, [sp]
	str	r1, [sp, #8]
	add	r7, sp, #28
	ldr	r0, [sp, #20]
	add	r1, sp, #252
.LVL1072:
	add	r2, sp, #92
	add	r3, sp, #76
.LVL1073:
	str	r7, [sp, #4]
	bl	_ZNK16btCollisionShape21calculateTemporalAabbERK11btTransformRK9btVector3S5_fRS3_S6_
.LVL1074:
.LBE7777:
	.loc 8 1019 0
	ldr	r3, [sp, #536]
	ldr	r1, [sp, #20]
	mov	r2, r4
	str	r3, [sp, #4]
	ldr	r3, [sp, #540]
	add	r0, sp, #316
	str	r6, [sp]
	str	r3, [sp, #8]
	mov	r3, r5
	bl	_ZN21btSingleSweepCallbackC1EPK13btConvexShapeRK11btTransformS5_PK16btCollisionWorldRNS6_20ConvexResultCallbackEf
	.loc 8 1021 0
	ldr	r0, [r6, #68]
.LVL1075:
	add	r2, sp, #44
	add	r1, sp, #172
	ldr	r3, [r0]
	str	r7, [sp]
	str	r2, [sp, #4]
	ldr	r4, [r3, #24]
.LVL1076:
	add	r2, sp, #236
	add	r3, sp, #316
	blx	r4
.LVL1077:
	ldr	r3, .L687+4
.LPIC134:
	add	r3, pc
.LBB7778:
.LBB7779:
.LBB7780:
.LBB7781:
.LBB7782:
.LBB7783:
.LBB7784:
	.loc 3 31 0
	ldr	r3, [r3]
	add	r3, r3, #8
	str	r3, [sp, #316]
.LBE7784:
.LBE7783:
.LBE7782:
.LBE7781:
.LBE7780:
.LBE7779:
.LBE7778:
.LBB7785:
.LBB7786:
.LBB7787:
	.loc 14 186 0
	bl	_ZN15CProfileManager12Stop_ProfileEv
.LBE7787:
.LBE7786:
.LBE7785:
.LBE7789:
	.loc 8 1050 0
	add	sp, sp, #508
	@ sp needed for prologue
.LVL1078:
.LVL1079:
	pop	{r0, r1, r4, r5, r6, r7, pc}
.L688:
	.align	2
.L687:
	.word	.LC9-(.LPIC132+4)
	.word	_ZTV24btBroadphaseAabbCallback(GOT_PREL)+(.-(.LPIC134+4))
	.cfi_endproc
.LFE1608:
	.fnend
	.size	_ZNK16btCollisionWorld15convexSweepTestEPK13btConvexShapeRK11btTransformS5_RNS_20ConvexResultCallbackEf, .-_ZNK16btCollisionWorld15convexSweepTestEPK13btConvexShapeRK11btTransformS5_RNS_20ConvexResultCallbackEf
	.section	.text._ZN16btCollisionWorld11contactTestEP17btCollisionObjectRNS_21ContactResultCallbackE,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorld11contactTestEP17btCollisionObjectRNS_21ContactResultCallbackE
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld11contactTestEP17btCollisionObjectRNS_21ContactResultCallbackE, %function
_ZN16btCollisionWorld11contactTestEP17btCollisionObjectRNS_21ContactResultCallbackE:
	.fnstart
.LFB1625:
	.loc 8 1158 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI120:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL1080:
.LBB7790:
.LBB7791:
.LBB7792:
	.loc 9 216 0
	mov	r3, r1
	add	r3, r3, #192
.LBE7792:
.LBE7791:
.LBE7790:
	.loc 8 1158 0
	mov	r6, r0
.LBB7801:
.LBB7794:
.LBB7793:
	.loc 9 216 0
	ldr	r0, [r3]
.LVL1081:
.LBE7793:
.LBE7794:
.LBE7801:
	.loc 8 1158 0
	.pad #52
	sub	sp, sp, #52
.LCFI121:
	.cfi_def_cfa_offset 72
.LVL1082:
	.loc 8 1158 0
	mov	r5, r1
.LBB7802:
	.loc 8 1160 0
	ldr	r3, [r0]
.LBE7802:
	.loc 8 1158 0
	mov	r7, r2
.LBB7803:
	.loc 8 1160 0
	add	r1, r1, #4
.LVL1083:
	ldr	r4, [r3, #8]
	mov	r2, sp
.LVL1084:
	add	r3, sp, #16
	blx	r4
.LVL1085:
.LBB7795:
.LBB7796:
.LBB7797:
	.loc 8 1122 0
	ldr	r3, .L696
.LBE7797:
.LBE7796:
.LBE7795:
	.loc 8 1163 0
	ldr	r0, [r6, #68]
.LBB7800:
.LBB7799:
.LBB7798:
	.loc 8 1122 0
	str	r5, [sp, #36]
.LPIC136:
	add	r3, pc
	ldr	r3, [r3]
	str	r6, [sp, #40]
	str	r7, [sp, #44]
	add	r3, r3, #8
	str	r3, [sp, #32]
.LBE7798:
.LBE7799:
.LBE7800:
	.loc 8 1163 0
	ldr	r3, [r0]
	mov	r1, sp
	add	r2, sp, #16
	ldr	r4, [r3, #28]
	add	r3, sp, #32
	blx	r4
.LVL1086:
.LBE7803:
	.loc 8 1164 0
	add	sp, sp, #52
.LVL1087:
	@ sp needed for prologue
.LVL1088:
.LVL1089:
.LVL1090:
	pop	{r4, r5, r6, r7, pc}
.L697:
	.align	2
.L696:
	.word	_ZTV23btSingleContactCallback(GOT_PREL)+(.-(.LPIC136+4))
	.cfi_endproc
.LFE1625:
	.fnend
	.size	_ZN16btCollisionWorld11contactTestEP17btCollisionObjectRNS_21ContactResultCallbackE, .-_ZN16btCollisionWorld11contactTestEP17btCollisionObjectRNS_21ContactResultCallbackE
	.section	.text._ZN16btCollisionWorld15contactPairTestEP17btCollisionObjectS1_RNS_21ContactResultCallbackE,"ax",%progbits
	.align	1
	.global	_ZN16btCollisionWorld15contactPairTestEP17btCollisionObjectS1_RNS_21ContactResultCallbackE
	.code	16
	.thumb_func
	.type	_ZN16btCollisionWorld15contactPairTestEP17btCollisionObjectS1_RNS_21ContactResultCallbackE, %function
_ZN16btCollisionWorld15contactPairTestEP17btCollisionObjectS1_RNS_21ContactResultCallbackE:
	.fnstart
.LFB1630:
	.loc 8 1170 0
	.cfi_startproc
	.save	{r4, r5, r6, r7, lr}
	push	{r4, r5, r6, r7, lr}
.LCFI122:
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL1091:
	mov	r7, r3
.LBB7804:
.LBB7805:
.LBB7806:
	.loc 9 216 0
	mov	r3, r1
.LVL1092:
	add	r3, r3, #192
.LBE7806:
.LBE7805:
.LBE7804:
	.loc 8 1170 0
	mov	r6, r0
.LBB7862:
.LBB7808:
.LBB7807:
	.loc 9 216 0
	ldr	r0, [r3]
.LVL1093:
.LBE7807:
.LBE7808:
.LBE7862:
	.loc 8 1170 0
	.pad #100
	sub	sp, sp, #100
.LCFI123:
	.cfi_def_cfa_offset 120
.LVL1094:
.LBB7863:
.LBB7809:
.LBB7810:
.LBB7811:
	.loc 13 35 0
	str	r1, [sp, #20]
	str	r0, [sp, #16]
.LBE7811:
.LBE7810:
.LBE7809:
.LBB7824:
.LBB7825:
	.loc 9 216 0
	mov	r0, r2
	add	r0, r0, #192
	ldr	r0, [r0]
.LBE7825:
.LBE7824:
.LBB7826:
.LBB7818:
.LBB7812:
	.loc 8 1171 0
	add	r1, r1, #4
.LVL1095:
	.loc 13 35 0
	str	r1, [sp, #24]
.LBE7812:
.LBE7818:
.LBE7826:
.LBB7827:
.LBB7828:
.LBB7829:
	str	r0, [sp, #40]
.LBE7829:
.LBE7828:
.LBE7827:
.LBB7838:
.LBB7819:
.LBB7813:
	mov	r1, #1
.LBE7813:
.LBE7819:
.LBE7838:
.LBB7839:
.LBB7840:
	.loc 4 133 0
	ldr	r0, [r6, #24]
.LBE7840:
.LBE7839:
.LBB7841:
.LBB7820:
.LBB7814:
	.loc 13 35 0
	neg	r1, r1
.LBE7814:
.LBE7820:
.LBE7841:
.LBB7842:
.LBB7834:
.LBB7830:
	str	r2, [sp, #44]
.LBE7830:
.LBE7834:
.LBE7842:
.LBB7843:
.LBB7821:
.LBB7815:
	mov	r3, #0
.LVL1096:
.LBE7815:
.LBE7821:
.LBE7843:
.LBB7844:
.LBB7835:
.LBB7831:
	.loc 8 1172 0
	add	r2, r2, #4
.LVL1097:
.LBE7831:
.LBE7835:
.LBE7844:
.LBB7845:
.LBB7822:
.LBB7816:
	.loc 13 35 0
	str	r1, [sp, #28]
	str	r1, [sp, #32]
.LVL1098:
.LBE7816:
.LBE7822:
.LBE7845:
.LBB7846:
.LBB7836:
.LBB7832:
	str	r1, [sp, #52]
	str	r1, [sp, #56]
.LVL1099:
	str	r2, [sp, #48]
.LBE7832:
.LBE7836:
.LBE7846:
.LBB7847:
.LBB7823:
.LBB7817:
	str	r3, [sp, #12]
.LBE7817:
.LBE7823:
.LBE7847:
.LBB7848:
.LBB7837:
.LBB7833:
	str	r3, [sp, #36]
.LBE7833:
.LBE7837:
.LBE7848:
	.loc 8 1174 0
	ldr	r2, [r0]
	add	r1, sp, #12
	ldr	r4, [r2, #8]
	add	r2, sp, #36
	blx	r4
.LVL1100:
.LBB7849:
	.loc 8 1175 0
	sub	r5, r0, #0
	beq	.L698
.LVL1101:
.LBB7850:
.LBB7851:
.LBB7852:
.LBB7853:
	.loc 8 1061 0
	add	r4, sp, #60
	mov	r0, r4
	add	r1, sp, #12
	add	r2, sp, #36
	bl	_ZN16btManifoldResultC2EPK24btCollisionObjectWrapperS2_
	ldr	r3, .L705
	str	r7, [r4, #32]
.LVL1102:
.LBE7853:
.LBE7852:
.LBE7851:
	.loc 8 1179 0
	add	r1, sp, #12
.LBB7858:
.LBB7856:
.LBB7854:
	.loc 8 1061 0
.LPIC138:
	add	r3, pc
	ldr	r3, [r3]
.LBE7854:
.LBE7856:
.LBE7858:
	.loc 8 1179 0
	mov	r0, r5
.LBB7859:
.LBB7857:
.LBB7855:
	.loc 8 1061 0
	add	r3, r3, #8
	str	r3, [sp, #60]
.LBE7855:
.LBE7857:
.LBE7859:
	.loc 8 1179 0
	ldr	r2, [r5]
	mov	r3, r6
	str	r4, [sp]
	add	r3, r3, #28
	ldr	r4, [r2, #8]
	add	r2, sp, #36
	blx	r4
	.loc 8 1181 0
	ldr	r3, [r5]
	mov	r0, r5
	ldr	r3, [r3]
	blx	r3
.LVL1103:
.LBB7860:
.LBB7861:
	.loc 4 133 0
	ldr	r0, [r6, #24]
.LBE7861:
.LBE7860:
	.loc 8 1182 0
	mov	r1, r5
	ldr	r3, [r0]
	ldr	r3, [r3, #60]
	blx	r3
.LVL1104:
.L698:
.LBE7850:
.LBE7849:
.LBE7863:
	.loc 8 1185 0
	add	sp, sp, #100
	@ sp needed for prologue
.LVL1105:
.LVL1106:
	pop	{r4, r5, r6, r7, pc}
.L706:
	.align	2
.L705:
	.word	_ZTV23btBridgedManifoldResult(GOT_PREL)+(.-(.LPIC138+4))
	.cfi_endproc
.LFE1630:
	.fnend
	.size	_ZN16btCollisionWorld15contactPairTestEP17btCollisionObjectS1_RNS_21ContactResultCallbackE, .-_ZN16btCollisionWorld15contactPairTestEP17btCollisionObjectS1_RNS_21ContactResultCallbackE
	.section	.text._ZN20btAlignedObjectArrayIPK10btDbvtNodeE7reserveEi,"axG",%progbits,_ZN20btAlignedObjectArrayIPK10btDbvtNodeE7reserveEi,comdat
	.align	1
	.weak	_ZN20btAlignedObjectArrayIPK10btDbvtNodeE7reserveEi
	.code	16
	.thumb_func
	.type	_ZN20btAlignedObjectArrayIPK10btDbvtNodeE7reserveEi, %function
_ZN20btAlignedObjectArrayIPK10btDbvtNodeE7reserveEi:
	.fnstart
.LFB1838:
	.loc 10 300 0
	.cfi_startproc
	.save	{r3, r4, r5, r6, r7, lr}
	push	{r3, r4, r5, r6, r7, lr}
.LCFI124:
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL1107:
.LBB7864:
	.loc 10 302 0
	ldr	r3, [r0, #8]
.LBE7864:
	.loc 10 300 0
	mov	r4, r0
	mov	r5, r1
.LBB7878:
	.loc 10 302 0
	cmp	r3, r1
	bge	.L707
.LVL1108:
.LBB7865:
.LBB7866:
.LBB7867:
	.loc 10 104 0
	sub	r6, r1, #0
	beq	.L709
.LVL1109:
.LBB7868:
.LBB7869:
	.loc 11 86 0
	lsl	r0, r1, #2
.LVL1110:
	mov	r1, #16
.LVL1111:
	bl	_Z22btAlignedAllocInternalji
	mov	r6, r0
.LVL1112:
.L709:
.LBE7869:
.LBE7868:
.LBE7867:
.LBE7866:
.LBB7870:
.LBB7871:
	.loc 10 151 0
	ldr	r1, [r4, #4]
.LVL1113:
	mov	r2, r6
	.loc 10 77 0
	mov	r3, #0
	b	.L710
.LVL1114:
.L712:
	.loc 10 300 0
	lsl	r0, r3, #2
.LVL1115:
.LBE7871:
.LBE7870:
.LBB7872:
.LBB7873:
	.loc 10 79 0
	cmp	r2, #0
	beq	.L711
	.loc 10 79 0 is_stmt 0 discriminator 1
	ldr	r7, [r4, #12]
	ldr	r0, [r7, r0]
.LVL1116:
	str	r0, [r2]
.L711:
	.loc 10 77 0 is_stmt 1
	add	r3, r3, #1
.LVL1117:
	add	r2, r2, #4
.LVL1118:
.L710:
	.loc 10 77 0 is_stmt 0 discriminator 1
	cmp	r3, r1
	blt	.L712
.LVL1119:
.LBE7873:
.LBE7872:
.LBB7874:
.LBB7875:
	.loc 10 111 0 is_stmt 1
	ldr	r0, [r4, #12]
	cmp	r0, #0
	beq	.L713
	.loc 10 113 0
	ldrb	r3, [r4, #16]
.LVL1120:
	cmp	r3, #0
	beq	.L713
.LVL1121:
.LBB7876:
.LBB7877:
	.loc 11 90 0
	bl	_Z21btAlignedFreeInternalPv
.LVL1122:
.L713:
.LBE7877:
.LBE7876:
.LBE7875:
.LBE7874:
	.loc 10 313 0
	mov	r3, #1
	strb	r3, [r4, #16]
	.loc 10 315 0
	str	r6, [r4, #12]
	.loc 10 317 0
	str	r5, [r4, #8]
.LVL1123:
.L707:
.LBE7865:
.LBE7878:
	.loc 10 320 0
	@ sp needed for prologue
.LVL1124:
.LVL1125:
	pop	{r3, r4, r5, r6, r7, pc}
	.cfi_endproc
.LFE1838:
	.fnend
	.size	_ZN20btAlignedObjectArrayIPK10btDbvtNodeE7reserveEi, .-_ZN20btAlignedObjectArrayIPK10btDbvtNodeE7reserveEi
	.section	.text._ZN20btAlignedObjectArrayIPK10btDbvtNodeE6resizeEiRKS2_,"axG",%progbits,_ZN20btAlignedObjectArrayIPK10btDbvtNodeE6resizeEiRKS2_,comdat
	.align	1
	.weak	_ZN20btAlignedObjectArrayIPK10btDbvtNodeE6resizeEiRKS2_
	.code	16
	.thumb_func
	.type	_ZN20btAlignedObjectArrayIPK10btDbvtNodeE6resizeEiRKS2_, %function
_ZN20btAlignedObjectArrayIPK10btDbvtNodeE6resizeEiRKS2_:
	.fnstart
.LFB1837:
	.loc 10 220 0
	.cfi_startproc
	.save	{r3, r4, r5, r6, r7, lr}
	push	{r3, r4, r5, r6, r7, lr}
.LCFI125:
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
.LVL1126:
.LBB7879:
.LBB7880:
.LBB7881:
	.loc 10 151 0
	ldr	r4, [r0, #4]
.LBE7881:
.LBE7880:
.LBE7879:
	.loc 10 220 0
	mov	r5, r0
	mov	r6, r1
	mov	r7, r2
.LBB7885:
.LBB7882:
	.loc 10 224 0
	cmp	r1, r4
	blt	.L717
.LVL1127:
.LBB7883:
	.loc 10 232 0
	ble	.L718
	.loc 10 234 0
	bl	_ZN20btAlignedObjectArrayIPK10btDbvtNodeE7reserveEi
.LVL1128:
.L718:
	lsl	r3, r4, #2
	b	.L719
.LVL1129:
.L721:
.LBB7884:
	.loc 10 239 0
	ldr	r2, [r5, #12]
	add	r2, r2, r3
.LVL1130:
	cmp	r2, #0
	beq	.L720
	.loc 10 239 0 is_stmt 0 discriminator 1
	ldr	r1,