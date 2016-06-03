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
	
	IND_Surface *mRed = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mRed, "../SpaceGame/resources/red.png", IND_ALPHA, IND_32)) return 0;
	IND_Surface *mBlue = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mBlue, "../SpaceGame/resources/blue.png", IND_ALPHA, IND_32)) return 0;

	IND_Animation *mAnimationCharacter1 = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationCharacter1, "../SpaceGame/resources/animations/character1.xml", IND_ALPHA, IND_32, 30, 59, 121)) return 0;
	IND_Animation *mAnimationCharacter2 = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationCharacter2, "../SpaceGame/resources/animations/character3.xml", IND_ALPHA, IND_32, 28, 28, 28)) return 0;

	// ----- Set the surface and animations into 2d entities -----

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

	IND_Entity2d *red = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(red);
	red->setSurface(mRed);

	IND_Entity2d *blue = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(blue);
	blue->setSurface(mBlue);

	// Character 1
	IND_Entity2d *mPlayer1 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mPlayer1);					// Entity adding
	mPlayer1->setAnimation(mAnimationCharacter1);			// Set the animation into the entity

	// Character 2
	IND_Entity2d *mPlayer2 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mPlayer2);					// Entity adding
	mPlayer2->setAnimation(mAnimationCharacter2);			// Set the animation into the entity

	// ----- Changing the attributes of the 2d entities -----

	mBack->setPosition(0, 0, 0);

	hbr1->setPosition(190, 0, 1);
	hbr2->setPosition(262, 0, 1);
	hbb1->setPosition(542, 0, 1);
	hbb2->setPosition(439, 0, 1);

	blue->setPosition(0, 275, 200);
	blue->setBoundingRectangle("blue", 5, 0, 54, 328);
	red->setPosition(470, 275, 200);
	blue->setBoundingRectangle("red", 740, 0, 54, 328);

	// Player 1
	mPlayer1->setSequence(0);						// Choose sequence
	mPlayer1->setMirrorX(1);						// Horizontal mirroring

	// Player 2
	mPlayer2->setSequence(0);						// Choose sequence

	// ----- Main Loop -----

	float mAngle = 0;
	float mPosX = 140;
	float mPosX1 = 530;
	float mPosY = 380;
	float mPosY1 = 380;
	float mPosZ = 5;
	float mPosZ1 = 5;
	int mSpeed = 200;
	float mDelta;
	char mText[2048];
	mText[0] = 0;

	float mWidth = mPlayer1->getRegionWidth() / 2;
	float mWidth1 = mPlayer2->getRegionWidth() / 2;

	float mHeight = mPlayer1->getRegionHeight() / 2;
	float mHeight1 = mPlayer2->getRegionHeight() / 2;

	while (!mI->_input->onKeyPress(IND_ESCAPE) && !mI->_input->quit())
	{
		// ----- Input update -----

		mI->_input->update();
		if (mPosX + mWidth >= mI->_window->getWidth()-120) mPosX = mI->_window->getWidth()-120;
		if (mPosX - mWidth < 5) mPosX = 5;

		if (mPosX1 + mWidth >= mI->_window->getWidth()-145) mPosX1 = mI->_window->getWidth()-145;
		if (mPosX1 - mWidth < -30) mPosX1 = -30;

		if (mPosY - mHeight >= mI->_window->getHeight()-150) mPosY = mI->_window->getHeight()-150;
		if (mPosY - mHeight < 355) mPosY = 355;

		if (mPosY1 - mHeight >= mI->_window->getHeight() - 150) mPosY1 = mI->_window->getHeight() - 150;
		if (mPosY1 - mHeight < 355) mPosY1 = 355;

		mDelta = mI->_render->getFrameTime() / 1000.0f;


		if (mI->_input->isKeyPressed(IND_D))
		{
			mPosX += mSpeed * mDelta;
		}

		if (mI->_input->isKeyPressed(IND_A))
		{
			mPosX -= mSpeed * mDelta;
		}

		if (mI->_input->isKeyPressed(IND_S))
		{
			mPosY += mSpeed * mDelta;
		}

		if (mI->_input->isKeyPressed(IND_W))
		{
			mPosY -= mSpeed * mDelta;
		}

		if (mI->_input->isKeyPressed(IND_KEYRIGHT))
		{
			mPosX1 += mSpeed * mDelta;
		}

		if (mI->_input->isKeyPressed(IND_KEYLEFT))
		{
			mPosX1 -= mSpeed * mDelta;
		}

		if (mI->_input->isKeyPressed(IND_KEYDOWN))
		{
			mPosY1 += mSpeed * mDelta;
		}

		if (mI->_input->isKeyPressed(IND_KEYUP))
		{
			mPosY1 -= mSpeed * mDelta;
		}

		if (mPosY1 < mPosY) mPosZ1 = 5 && mPosZ == mPosZ++;
		else if (mPosY1 > mPosY) mPosZ = 5 && mPosZ1 == mPosZ++;

		mPlayer1->setPosition((float)mPosX, (float)mPosY, (float)mPosZ);
		mPlayer2->setPosition((float)mPosX1, (float)mPosY1, (float)mPosZ1);

		if (mI->_entity2dManager->isCollision(mPlayer1, "first", blue, "blue"))
		{

		}
		if (mI->_entity2dManager->isCollision(mPlayer2, "second", blue, "blue"))
		{

		}
		if (mI->_entity2dManager->isCollision(mPlayer1, "first", blue, "red"))
		{

		}
		if (mI->_entity2dManager->isCollision(mPlayer1, "second", blue, "red"))
		{

		}

		if (mPosX >= mPosX1)
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
		mI->_render->clearViewPort(0, 0, 0);
		mI->_entity2dManager->renderEntities2d();
		mI->_entity2dManager->renderCollisionAreas(255, 0, 0, 255);
		mI->_render->endScene();
	}

	mI->end();
	return 0;
}