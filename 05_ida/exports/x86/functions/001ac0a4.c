/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac0a4. */
int __cdecl -[IOSCSIController getIntValues:forParameter:count:](
        IOSCSIController *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int *a5)
{
  int i; // eax
  unsigned int v7; // [esp+Ch] [ebp-18h]
  objc_super v8; // [esp+10h] [ebp-14h] BYREF
  _DWORD v9[3]; // [esp+18h] [ebp-Ch]

  v7 = *a5; /*0x1ac0b5*/
  if ( !*a5 ) /*0x1ac0b5*/
    v7 = 512; /*0x1ac0bf*/
  if ( !strcmp(a4, "IOSCSIControllerStatistics") ) /*0x1ac0d5*/
  {
    v9[0] = -[IOSCSIController maxQueueLength](self, sel_maxQueueLength); /*0x1ac0e9*/
    v9[1] = -[IOSCSIController numQueueSamples](self, sel_numQueueSamples); /*0x1ac0fc*/
    v9[2] = -[IOSCSIController sumQueueLengths](self, sel_sumQueueLengths); /*0x1ac10f*/
    *a5 = 0; /*0x1ac115*/
    for ( i = 0; i <= 2; ++i ) /*0x1ac11b*/
    {
      if ( *a5 == v7 ) /*0x1ac125*/
        break; /*0x1ac125*/
      a3[i] = v9[i]; /*0x1ac12e*/
      ++*a5; /*0x1ac131*/
    }
    return 0; /*0x1ac139*/
  }
  else if ( !strcmp(a4, "IOIsASCSIController") ) /*0x1ac151*/
  {
    *a5 = 0; /*0x1ac183*/
    return 0; /*0x1ac189*/
  }
  else
  {
    v8.receiver = self; /*0x1ac166*/
    v8.super_class = (Class)stru_1FA334.ext; /*0x1ac16f*/
    return -[IODevice getIntValues:forParameter:count:](&v8, sel_getIntValues_forParameter_count_, a3, a4, a5); /*0x1ac176*/
  }
}
