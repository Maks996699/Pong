//
//                Left30*___________________*Right30
//                      |*                 *|
//                      | *               * |
//             Left45*  |  *             *  |  *Right45
//     Left60*   ______*|___*___________*___|*______   *Right60
//              |*      |*   *         *   *|      *|   
//              |    *  |  *  *       *  *  |  *    |
//              |       |*   * *     * *   *|       |
//              |       |    * **   ** *    |       |
//              |       |        * *        |       |
//              |       |        * *        |       |
//	            |       |    * **   ** *    |       |
//	            |       |*   * *     * *   *|       |
//        	    |    *  |  *  *       *  *  |  *    |
//        	    |*______|*___*_________*___*|______*|
//    Left120*         *|   *           *   |*         *Right120
//            Left135*  |  *             *  |  *Right135
//                      | *               * |
//                      |*_________________*|
//               Left150*                   *Right150 
//
//
//
//
//
//
//
//

#ifndef Ball_h
#define Ball_h
#include "GameObject.h"

enum class BallState {
	Right30, Right150, Left30, Left150, 
	Right45, Right135, Left45, Left135, 
	Right60, Right120, Left60, Left120,
	Right, Left
};


class Ball : public GameObject
{
public:
	Ball(const char* texturesheet, int x, int y);
	~Ball();
	void setState(BallState& state);
	void update();
	void chengeStateFromCollisionWithPlayer();
	void changeStateFromCollisionWithEnemy();
	void reboundFromUp();
	void reboundFromDown();
	void reboundFromRight();
	void reboundFromLeft();

private:
	int speed;
	BallState state;

};

#endif