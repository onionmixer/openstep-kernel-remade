/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ad61c. */
int __cdecl -[SCSIDisk deviceRwCommon:block:length:buffer:client:pending:actualLength:](
        SCSIDisk *self,
        SEL a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        void *a6,
        unsigned int a7,
        void *a8,
        unsigned int *a9)
{
  id v9; // eax
  id v10; // esi
  unsigned int v13; // ebx
  unsigned int v14; // esi
  $BB0ECD142E749ABD0946980FC80D177E *v15; // ebx
  id v16; // [esp+Ch] [ebp-4h]

  v9 = -[SCSIDisk isDiskReady:](self, sel_isDiskReady_, 1); /*0x1ad631*/
  v10 = v9; /*0x1ad636*/
  if ( v9 == (id)-1102 ) /*0x1ad641*/
    return -1102; /*0x1ad651*/
  if ( v9 )
  {
    -[IODisk stringFromReturn:](self, sel_stringFromReturn_, v9); /*0x1ad661*/
    -[IODevice name](self, sel_name); /*0x1ad670*/
    IOLog("%s deviceRwCommon: bogus return from isDiskReady (%s)\n");
  }
  else
  {
    if ( !-[IODisk isFormatted](self, sel_isFormatted) ) /*0x1ad694*/
      return -1101; /*0x1ad6a7*/
    v13 = -[IODisk blockSize](self, sel_blockSize); /*0x1ad6b8*/
    v16 = -[IODisk diskSize](self, sel_diskSize); /*0x1ad6c7*/
    if ( a5 % v13 ) /*0x1ad6d1*/
      return -1; /*0x1ad6e1*/
    v14 = a5 / v13; /*0x1ad6e8*/
    if ( (unsigned int)v16 < a5 / v13 + a4 ) /*0x1ad6f2*/
    {
      if ( a4 >= (unsigned int)v16 ) /*0x1ad6fa*/
        return -706; /*0x1ad701*/
      v14 = (unsigned int)v16 - a4; /*0x1ad707*/
    }
    v15 = -[SCSIDisk allocSdBuf:](self, sel_allocSdBuf_, a8); /*0x1ad71a*/
    v15->var0 = a3; /*0x1ad71f*/
    v15->var1 = a4; /*0x1ad724*/
    v15->var2 = v14; /*0x1ad727*/
    v15->var3 = a6; /*0x1ad72d*/
    v15->var4 = a7; /*0x1ad733*/
    *((_BYTE *)v15 + 32) |= 1u; /*0x1ad736*/
    v10 = -[SCSIDisk enqueueSdBuf:](self, sel_enqueueSdBuf_, v15); /*0x1ad748*/
    if ( !a8 ) /*0x1ad751*/
    {
      *a9 = v15->var10; /*0x1ad759*/
      -[SCSIDisk freeSdBuf:](self, sel_freeSdBuf_, v15); /*0x1ad763*/
    }
  }
  return (int)v10; /*0x1ad76d*/
}
