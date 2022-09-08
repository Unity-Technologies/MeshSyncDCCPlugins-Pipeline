# MeshSyncDCCPlugins Usage in Modo

<img src="https://user-images.githubusercontent.com/1488611/55697991-d9135980-59fe-11e9-8e9f-8fcfba1b234f.png" height=300><img src="https://user-images.githubusercontent.com/1488611/55697990-d9135980-59fe-11e9-9312-29c95e20e5b0.png" height=300>

- Installation:
   - Designate MeshSyncClientModo.fx in Modo under System -> Add Plug-in
- After installing, View will be added to the menu (Application -> Custom View -> UnityMeshSync), where varous options and settings can be accessed
- While "Auto Sync" is checked, changes made to the mesh will automatically be reflected in Unity. If Auto Sync is disabled, the "Manual Sync" button can be used to sync changes
- Clicking Sync under Animations will cause the timer to advance from the first frame to the final frame while baking the animation and sending it to Unity.

&nbsp;

- Portions of Mesh Instance and Replicator are also supported.
- Polygon mesh Skinning/Joints and Morph will carry over to Unity, but be aware of how deformers are handled.
   - MeshSync can only handle Joint + Weight Map skinning, or Morph deformers. Any other deformers will be ignored.
   - Checking "Bake Deformers" will send the results of applying all deformers to Unity. This will mostly synchronize the Mesh on the Unity side even with complex deformer compositions, but comes at the cost of losing skinning and Morph/Blendshape information.
   - Mesh Instance and Replicator skinning won't display properly in Unity. "Bake Deformers" must be used.
- MeshSync features can also be accessed via commands. Use unity.meshsync.settings to change settings, and unity.meshsync.export to export

&nbsp;

As of Modo 13, the  [Mood Bridge for Unity](https://learn.foundry.com/modo/content/help/pages/appendices/modo_bridge.html) feature is available. This feature allows you to send Meshes and Materials directly to Unity.It has elements that are similar to MeshSync's features, with the following differences (as of 04/2019).
- Mood Bridge supports Modo <-> Unity sync in both directions. MeshSync only supports Modo -> Unity sync.
- MeshSync can sync Replicator and Mesh Skinning/Morphs, and animations. Currently, Mood Bridge cannot.
- MeshSync attempts to replicate the results of bringing data into Unity via FBX as much as possible. On the other hand Modo Bridge has big differences such as using a different coordinate system (Z direction is reversed), decompressing the Mesh index (a model with 1,000 triangles will have 3,000 vertices), etc.