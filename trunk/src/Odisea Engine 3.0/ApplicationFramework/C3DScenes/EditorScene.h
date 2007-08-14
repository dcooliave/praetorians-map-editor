#ifndef EDITORSCENE
#define EDITORSCENE

#include "Scene.h"
#include "Renderer/Renderer.h"
#include "../C3DGeometry/Grid.h"
#include "../C3DParsers/PveObject.h"

class EditorScene : public Scene
{
  public:
  	EditorScene(const String &name = "EditorScene");
  	virtual ~EditorScene();
  
  public:
    virtual void actionPerformed(GUIEvent &evt);

    virtual void HandleMouseEvent(MouseEvent evt, int extraInfo);
    virtual void HandleKeyEvent(KeyEvent evt, int extraInfo);
    
    virtual bool Initialize();
    virtual void BeginScene();
    virtual void Update(const FrameInfo &frameInfo);

  private:
    GUILabel   *m_pFpsCounter;
    Frustum     m_Frustum;
    Camera      m_Camera;
    Grid        m_Grid;

    PveObject   m_PveObject;
    
    bool        mouseLocked;
};

#endif