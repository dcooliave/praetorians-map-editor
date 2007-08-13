#ifndef CAMERA_H
#define CAMERA_H

#include "../Math/MathUtils.h"
#include "../Events/KeyEvent.h"

class Camera
{
  public:
    Camera(float positionX = 0.0f, float positionY = 0.0f, float positionZ = 0.0f,
           float focusX    = 0.0f, float focusY    = 0.0f, float focusZ    = 0.0f,
           float upVectorX = 0.0f, float upVectorY = 1.0f, float upVectorZ = 0.0f);

    void setup(const Tuple3f &position,
               const Tuple3f &focus,
               const Tuple3f &up);

    void setup(float positionX, float positionY, float positionZ,
               float focusX   , float focusY   , float focusZ   ,
               float upVectorX, float upVectorY, float upVectorZ);

    void lockMouse(bool);
    void activate();
    void deactivate();

    void setKeyboardInput(KeyEvent &event, bool active);
    void update(float timeFrame);
    void look();

    void     setMouseInfo(Tuple2i &mousePosition);
    void     setMouseInfo(int x = 0, int y = 0);

    void     setViewerPosition(const Tuple3f &position);
    void     setFocusPosition (const Tuple3f &focus);
    void     setUpDirection   (const Tuple3f &up);

    void     setMouseSensitivity(float zeroToOne);
    void     setTranslationSpeed(float zeroToOne);

    const Matrix4f &getModelViewMatrix() const;
    const Tuple3f  &getViewerPosition()  const;
    const Tuple3f  &getFocusPosition()   const;
    const Tuple3f  &getUpDirection()     const;
    void  elevate   (float speed);

  private:
    void processKeyboardEvents();
    void rotateAroundPoint(Tuple3f &vCenter, float x, float y, float z);
    void setViewByMouse();
    void rotateView(float angle, float X, float Y, float Z);
    void strafeMove(float speed);
    void move      (float speed);

    Tuple2i  mouseLockedPosition,
             mousePosition;

    float    mouseSensitivity,
             translationSpeed,
             currentXRotation,
             speed;

    Matrix4f viewMatrix;

    Tuple3f  position,
             strafe,
             focus,
             up;

    bool     activeKeys[6],
             mouseLocked,
             active;
};

#endif