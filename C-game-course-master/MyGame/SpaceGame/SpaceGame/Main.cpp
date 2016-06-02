/*****************************************************************************************
* Desc: Tutorial 02 IND_Surface
*****************************************************************************************/

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"

/*
==================
Main
==================
*/
int IndieLib()
{
	
	// ----- IndieLib intialization -----

	CIndieLib *mI = CIndieLib::instance();
	if (!mI->init()) return 0;

	
	// ----- Surface loading -----

	// Loading Background
	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBack, "../SpaceGame/resources/background2.jpg", IND_OPAQUE, IND_32)) return 0;

	// Loading healthbars
	IND_Surface *mSurfaceHBR1 = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceHBR1, "../SpaceGame/resources/hbr1.png", IND_ALPHA, IND_32)) return 0;
	IND_Surface *mSurfaceHBR2 = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceHBR2, "../SpaceGame/resources/hbr2.png", IND_ALPHA, IND_32)) return 0;
	IND_Surface *mSurfaceHBB1 = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceHBB1, "../SpaceGame/resources/hbb1.png", IND_ALPHA, IND_32)) return 0;
	IND_Surface *mSurfaceHBB2 = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceHBB2, "../SpaceGame/resources/hbb2.png", IND_ALPHA, IND_32)) return 0;


	// ----- Animations loading -----

	// Characters animations, we apply a color key of (30, 59, 121)
	IND_Animation *mAnimationCharacter1 = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationCharacter1, "../SpaceGame/resources/animations/character1.xml", IND_ALPHA, IND_32, 30, 59, 121)) return 0;

	// Characters animations, we apply a color key of (38, 62, 114)
	IND_Animation *mAnimationCharacter2 = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationCharacter2, "../SpaceGame/resources/animations/character3.xml", IND_ALPHA, IND_32, 28, 28, 28)) return 0;

	// Dust animation, we apply a color key of (255, 0, 255)
	//IND_Animation *mAnimationDust = IND_Animation::newAnimation();
	//if (!mI->_animationManager->addToSurface(mAnimationDust, "../SpaceGame/resources/animations/dust.xml", IND_ALPHA, IND_16, 255, 0, 255)) return 0;

	// ----- Set the surface and animations into 2d entities -----

	// Creating 2d entity for the background
	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);					// Entity adding
	mBack->setSurface(mSurfaceBack);					// Set the surface into the entity

	IND_Entity2d *hbr1 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(hbr1);
	hbr1->setSurface(mSurfaceHBR1);

	IND_Entity2d *hbr2 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(hbr2);
	hbr2->setSurface(mSurfaceHBR2);

	IND_Entity2d *hbb1 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(hbb1);
	hbb1->setSurface(mSurfaceHBB1);

	IND_Entity2d *hbb2 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(hbb2);
	hbb2->setSurface(mSurfaceHBB2);

	// Character 1
	IND_Entity2d *mPlayer1 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mPlayer1);					// Entity adding
	mPlayer1->setAnimation(mAnimationCharacter1);				// Set the animation into the entity

	// Character 2
	IND_Entity2d *mPlayer2 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mPlayer2);					// Entity adding
	mPlayer2->setAnimation(mAnimationCharacter2);				// Set the animation into the entity

	// Dust explosion
	//IND_Entity2d *mDust = IND_Entity2d::newEntity2d();
	//mI->_entity2dManager->add(mDust);					// Entity adding
	//mDust->setAnimation(mAnimationDust);					// Set the animation into the entity

	// ----- Changing the attributes of the 2d entities -----

	// Player 1
	mPlayer1->setSequence(0);						// Choose sequence
	mPlayer1->setPosition(140, 380, 0);
	mPlayer1->setMirrorX(1);						// Horizontal mirroring

	// Dust explosion
	//mDust->setPosition(360, 250, 0);

	// Player 2
	mPlayer2->setSequence(0);						// Choose sequence
	mPlayer2->setPosition(550, 380, 0);
	//mPlayer2->setNumReplays(3);						// The animation will be displayed 3 times

	hbr1->setPosition(190, 0, 100);
	hbr2->setPosition(262, 0, 100);
	hbb1->setPosition(542, 0, 100);
	hbb2->setPosition(439, 0, 100);

	// ----- Main Loop -----

	float mAngle = 0;
	float mPos = 140;
	float mPos1 = 530;
	int mSpeed = 200;
	float mDelta;
	char mText[2048];
	mText[0] = 0;

	while (!mI->_input->onKeyPress(IND_ESCAPE) && !mI->_input->quit())
	{
		// ----- Input update -----

		mI->_input->update();
		mDelta = mI->_render->getFrameTime() / 1000.0f;

		if (mI->_input->isKeyPressed(IND_D))
		{
			mPos += mSpeed * mDelta;
		}

		if (mI->_input->isKeyPressed(IND_A))
		{
			mPos -= mSpeed * mDelta;
		}

		if (mI->_input->isKeyPressed(IND_KEYRIGHT))
		{
			mPos1 += mSpeed * mDelta;
		}

		if (mI->_input->isKeyPressed(IND_KEYLEFT))
		{
			mPos1 -= mSpeed * mDelta;
		}

		mPlayer1->setPosition((float)mPos, 380, 0);
		mPlayer2->setPosition((float)mPos1, 380, 0);


		if (mPos >= mPos1)
		{
			mPlayer1->setMirrorX(0);
			mPlayer2->setMirrorX(0);
		}
		else
		{
			mPlayer1->setMirrorX(1);
			mPlayer2->setMirrorX(1);
		}

		mI->_render->beginScene();
		mI->_entity2dManager->renderEntities2d();
		mI->_render->endScene();
	}

	mI->end();
	return 0;
}