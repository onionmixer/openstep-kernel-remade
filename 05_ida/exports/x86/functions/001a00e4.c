/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a00e4. */
id __cdecl -[EventSrcPCPointer scalePointerInX:andY:over:atRes:](
        EventSrcPCPointer *self,
        SEL a2,
        int *a3,
        int *a4,
        unsigned int a5,
        unsigned int a6)
{
  unsigned int v6; // ebx
  unsigned int v7; // ebx
  int v8; // ecx
  int numScaleLevels; // edx
  int v10; // edx
  int v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // eax
  int v15; // edx
  int resScaling; // [esp+Ch] [ebp-18h]
  int v18; // [esp+14h] [ebp-10h]
  int v19; // [esp+18h] [ebp-Ch]
  int v20; // [esp+1Ch] [ebp-8h]
  int v21; // [esp+20h] [ebp-4h]

  v6 = a5; /*0x1a00f0*/
  v21 = *a3; /*0x1a00f8*/
  v20 = *a4; /*0x1a0100*/
  v19 = *a3; /*0x1a0103*/
  if ( *a3 < 0 ) /*0x1a0108*/
    v19 = -v19; /*0x1a010a*/
  v18 = *a4; /*0x1a0110*/
  if ( v20 < 0 ) /*0x1a0115*/
    v18 = -v20; /*0x1a0117*/
  if ( !a5 ) /*0x1a0122*/
    v6 = 1; /*0x1a0124*/
  v7 = 15259 * (v18 + v19) / (a6 * v6); /*0x1a0154*/
  resScaling = self->resScaling; /*0x1a015c*/
  if ( v7 > self->pointerScaling.scaleThresholds[0] ) /*0x1a0168*/
  {
    v8 = 1; /*0x1a016a*/
    numScaleLevels = self->pointerScaling.numScaleLevels; /*0x1a016f*/
    if ( numScaleLevels > 1 ) /*0x1a0177*/
    {
      do /*0x1a018b*/
      {
        if ( v7 <= self->pointerScaling.scaleThresholds[v8] ) /*0x1a0186*/
          break; /*0x1a0186*/
        ++v8; /*0x1a0188*/
      }
      while ( v8 < numScaleLevels ); /*0x1a018b*/
    }
    resScaling *= self->pointerScaling.scaleThresholds[v8 + 19]; /*0x1a0199*/
  }
  if ( v21 < 0 ) /*0x1a01a0*/
  {
    v12 = resScaling * v19 - (self->dxRemainder - 128); /*0x1a01e0*/
    *a3 = -(v12 >> 8); /*0x1a01ec*/
    v11 = 128 - (unsigned __int8)v12; /*0x1a01fc*/
  }
  else
  {
    v10 = resScaling * v21 + self->dxRemainder + 128; /*0x1a01b5*/
    *a3 = v10 >> 8; /*0x1a01bf*/
    v11 = (unsigned __int8)v10 - 128; /*0x1a01c9*/
  }
  self->dxRemainder = v11; /*0x1a01fe*/
  if ( v20 < 0 ) /*0x1a0208*/
  {
    v15 = resScaling * v18 - (self->dyRemainder - 128); /*0x1a0248*/
    *a4 = -(v15 >> 8); /*0x1a0254*/
    v14 = 128 - (unsigned __int8)v15; /*0x1a0264*/
  }
  else
  {
    v13 = resScaling * v20 + self->dyRemainder + 128; /*0x1a021d*/
    *a4 = v13 >> 8; /*0x1a0227*/
    v14 = (unsigned __int8)v13 - 128; /*0x1a0231*/
  }
  self->dyRemainder = v14; /*0x1a0266*/
  return self; /*0x1a0271*/
}
