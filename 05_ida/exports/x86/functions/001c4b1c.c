/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c4b1c. */
char __cdecl -[IOFrameBufferDisplay _commitToPendingMode](IOFrameBufferDisplay *self, SEL a2)
{
  $514E7C50D28E54AB164B6500F83867A3 *v2; // eax
  unsigned int var9; // eax
  $514E7C50D28E54AB164B6500F83867A3 *v5; // [esp+10h] [ebp-18h]
  $514E7C50D28E54AB164B6500F83867A3 *v6; // [esp+18h] [ebp-10h]
  $514E7C50D28E54AB164B6500F83867A3 *v7; // [esp+1Ch] [ebp-Ch]
  int pendingDisplayMode; // [esp+24h] [ebp-4h]

  pendingDisplayMode = self->_pendingDisplayMode; /*0x1c4b2e*/
  v5 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c4b41*/
  v2 = -[IOFrameBufferDisplay displayModes](self, sel_displayModes); /*0x1c4b4f*/
  if ( !v2 ) /*0x1c4b5b*/
    return 0; /*0x1c4b5d*/
  v6 = v2; /*0x1c4b70*/
  bzero(v5->var8, 0x40u); /*0x1c4b73*/
  v7 = &v6[pendingDisplayMode]; /*0x1c4b8a*/
  strncpy(v5->var8, v7->var8, strlen(v7->var8)); /*0x1c4bae*/
  v5->var0 = v7->var0; /*0x1c4bbb*/
  v5->var1 = v7->var1; /*0x1c4bc4*/
  v5->var2 = v7->var2; /*0x1c4bcb*/
  v5->var3 = v7->var3; /*0x1c4bd2*/
  v5->var4 = v7->var4; /*0x1c4bd9*/
  v5->var6 = v7->var6; /*0x1c4be0*/
  v5->var7 = v7->var7; /*0x1c4be7*/
  v5->var10 = v7->var10; /*0x1c4bee*/
  v5->var15 = v7->var15; /*0x1c4bf5*/
  v5->var16 = v7->var16; /*0x1c4bfc*/
  v5->var12 = v7->var12; /*0x1c4c03*/
  v5->var11 = v7->var11; /*0x1c4c0a*/
  v5->var14 = v7->var14; /*0x1c4c11*/
  v5->var17 = v7->var17; /*0x1c4c1b*/
  var9 = v7->var9; /*0x1c4c21*/
  if ( var9 ) /*0x1c4c27*/
  {
    v5->var9 = var9; /*0x1c4c29*/
  }
  else if ( v5->var6 == 1 ) /*0x1c4c37*/
  {
    v5->var9 = 16; /*0x1c4c39*/
  }
  else
  {
    v5->var9 = 2; /*0x1c4c47*/
  }
  self->_currentDisplayMode = pendingDisplayMode; /*0x1c4c54*/
  return 1; /*0x1c4c62*/
}
