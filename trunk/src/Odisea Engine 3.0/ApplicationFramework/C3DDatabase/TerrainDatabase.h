#ifndef TERRAINDATABASE
#define TERRAINDATABASE

#include "../C3DGraphs/TileGraph.h"
#include "../C3DParsers/PveObject.h"
#include "../C3DParsers/PteObject.h"
#include "../C3DNodes/SpatialIndexNode.h"
#include "../C3DNodes/SpatialIndexCell.h"
#include "../C3DControllers/TileModelController.h"

class GameFileDescriptor
{
  public:
    String pvePath;
    String ptePath;
};

class TerrainDatabase
{
  public:
     TerrainDatabase(){}
    ~TerrainDatabase();
    
    void LoadGameData(const GameFileDescriptor &descriptor);
    void Draw(unsigned int level, TileGraphVisitor *visitor);
    void Cull(TileGraphVisitor *visitor);//name change: Accept
    
    void CellVisibility(const Tuple4i &range, bool value);
    void ControllerVisibility(const Tuple4i &range, bool value);
  
  private:
    void SetupSpatialIndexStructure(void);
    void SetupCellDataStructures(void);
    void SetupGraphStructure(void);
    
    void ComputeCellBoundaries(void);
    void ComputeTreeBoundaries(void);
  
  private:
    PveObject m_PveObject;
    PteObject m_PteObject;
    
    TileGraph m_TileGraph;
    
    ResourceManager <TileModelController, 1e5> m_ManagedTileModelControllers;
    ResourceManager <SpatialIndexBaseNode,1e2> m_ManagedBases;
    ResourceManager <SpatialIndexNode,    1e2> m_ManagedNodes;
    ResourceManager <SpatialIndexCell,    1e2> m_ManagedCells;
    
    ArrayPtr <TileModelController>  m_Controllers;
    ArrayPtr <SpatialIndexCell> m_SpatialIndexCells;
    ArrayPtr <SpatialIndexBaseNode> m_SpatialIndexBranches;
    
    SpatialIndexBaseNode *m_pTrunk;
};

#endif