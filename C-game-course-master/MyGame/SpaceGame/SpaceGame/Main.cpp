/*****************************************************************************************
* Desc: Tutorial 02 IND_Surface
*****************************************************************************************/

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "IND_Font.h"

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
	IND_Surface *mEmpty = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mEmpty, "../SpaceGame/resources/desperate.png", IND_ALPHA, IND_32)) return 0;
	IND_Surface *endBlue = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(endBlue, "../SpaceGame/resources/gameoverblue.jpg", IND_ALPHA, IND_32)) return 0;
	IND_Surface *endRed = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(endRed, "../SpaceGame/resources/gameoverred.jpg", IND_ALPHA, IND_32)) return 0;

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

	IND_Entity2d *red1 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(red1);
	red1->setSurface(mRed);

	IND_Entity2d *blue = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(blue);
	blue->setSurface(mBlue);

	IND_Entity2d *blue1 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(blue1);
	blue1->setSurface(mBlue);

	IND_Entity2d *empty = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(empty);
	empty->setSurface(mEmpty);

	/*IND_Entity2d *endingred = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(endingred);
	endingred->setSurface(endRed);*/

	IND_Entity2d *empty1 = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(empty1);
	empty1->setSurface(mEmpty);

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

	blue->setPosition(0, 275, 5000);
	blue->setBoundingRectangle("blue", 5, 0, 54, 328);
	blue1->setPosition(-100, 275, 5000);
	blue1->setBoundingRectangle("blue1", 5, 0, 54, 328);
	red->setPosition(471, 275, 5000);
	red->setBoundingRectangle("red", 270, 0, 54, 328);
	red1->setPosition(800, 275, 5000);
	red1->setBoundingRectangle("red1", 270, 0, 54, 328);

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
	bool pShow;

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

		if (mI->_entity2dManager->isCollision(mPlayer1, "player1", blue, "blue"))
		{
			hbr2->setPosition(262, 0, -1);
			blue->setPosition(-100, 275, 5000);
			empty->setPosition(100, 400, 5000);
			empty->setBoundingRectangle("empty", 300, 20, 5, 475);
		}
		if (mI->_entity2dManager->isCollision(mPlayer1, "player1", empty, "empty"))
		{
			blue1->setPosition(0, 275, 5000);
		}
		if (mI->_entity2dManager->isCollision(mPlayer1, "player1", blue1, "blue1"))
		{
			hbr1->setPosition(262, 0, -1);
			mI->_entity2dManager->remove(mPlayer1);
			mI->_entity2dManager->remove(mPlayer2);
			mI->_entity2dManager->remove(red1);
			mI->_entity2dManager->remove(red);
			mI->_entity2dManager->remove(blue1);
			mI->_entity2dManager->remove(blue);
			mI->_entity2dManager->remove(hbb1);
			mI->_entity2dManager->remove(hbb2);
			mI->_entity2dManager->remove(hbr1);
			mI->_entity2dManager->remove(hbr2);
			IND_Entity2d *endingblue = IND_Entity2d::newEntity2d();
			mI->_entity2dManager->add(endingblue);
			endingblue->setSurface(endBlue);
		}
		if (mI->_entity2dManager->isCollision(mPlayer1, "player1", red, "red"))
		{
			blue1->setPosition(-100, 275, 5000);
			blue->setPosition(0, 275, 5000);
			empty->setPosition(-900, 0, 0);
			hbr2->setPosition(262, 0, 1);
		}

		if (mI->_entity2dManager->isCollision(mPlayer2, "player2", red, "red"))
		{
			hbb2->setPosition(439, 0, -1);
			red->setPosition(800, 275, 5000);
			empty1->setPosition(100, 400, 5000);
			empty1->setBoundingRectangle("empty1", 300, 20, 5, 475);
		}
		if (mI->_entity2dManager->isCollision(mPlayer2, "player2", empty1, "empty1"))
		{
			red1->setPosition(471, 275, 5000);
		}
		if (mI->_entity2dManager->isCollision(mPlayer2, "player2", red1, "red1"))
		{
			hbb1->setPosition(542, 0, -1);
			mI->_entity2dManager->remove(mPlayer1);
			mI->_entity2dManager->remove(mPlayer2);
			mI->_entity2dManager->remove(red1);
			mI->_entity2dManager->remove(red);
			mI->_entity2dManager->remove(blue1);
			mI->_entity2dManager->remove(blue);
			mI->_entity2dManager->remove(hbb1);
			mI->_entity2dManager->remove(hbb2);
			mI->_entity2dManager->remove(hbr1);
			mI->_entity2dManager->remove(hbr2);
			IND_Entity2d *endingred = IND_Entity2d::newEntity2d();
			mI->_entity2dManager->add(endingred);
			endingred->setSurface(endRed);
		}

		if (mI->_entity2dManager->isCollision(mPlayer2, "player2", blue, "blue"))
		{
			red1->setPosition(1900, 275, 5000);
			red->setPosition(471, 275, 5000);
			empty1->setPosition(1900, 0, 0);
			hbb2->setPosition(439, 0, 1);
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
		
		//float fps = 1 / mDelta;
		
		mI->_render->beginScene(); 
		mI->_render->clearViewPort(0, 0, 0);
		mI->_entity2dManager->renderEntities2d();
		mI->_render->showFpsInWindowTitle();
		//mI->_entity2dManager->renderCollisionAreas(255, 0, 0, 255);
		mI->_render->endScene();
	}

	mI->end();
	return 0;
}