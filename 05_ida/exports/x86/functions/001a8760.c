/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8760. */
int __cdecl -[IODirectDevice waitForInterrupt:](IODirectDevice *self, SEL a2, int *a3)
{
  __int16 v3; // si
  const char *v5; // eax
  int v6; // eax
  int v7; // ebx
  const char *v8; // [esp-8h] [ebp-2Ch]
  int v9; // [esp-4h] [ebp-28h]
  _DWORD v10[6]; // [esp+Ch] [ebp-18h] BYREF

  v3 = 4352; /*0x1a876c*/
  if ( !self->_interruptPort ) /*0x1a8771*/
    return -735; /*0x1a877a*/
  do
  {
    v10[1] = 24; /*0x1a87c4*/
    v10[3] = self->_interruptPort; /*0x1a87d1*/
    v6 = msg_receive(v10, v3, 0); /*0x1a87db*/
    v7 = v6; /*0x1a87e0*/
    if ( v6 == -204 ) /*0x1a87eb*/
      return -737; /*0x1a8789*/
    if ( v6 && v6 != -203 )
    {
      v9 = v6; /*0x1a8790*/
      v8 = -[IODevice deviceKind](self, sel_deviceKind); /*0x1a87a1*/
      v5 = -[IODevice name](self, sel_name); /*0x1a87aa*/
      IOLog((int)"%s: %s waitForInterrupt: msg_receive returns %d\n", v5, v8, v9);
      return -703; /*0x1a87c2*/
    }
    if ( (v3 & 0x100) != 0 ) /*0x1a87ff*/
    {
      if ( v6 == -203 ) /*0x1a8807*/
        v3 = 4096; /*0x1a8809*/
      else
        thread_block(); /*0x1a8810*/
    }
  }
  while ( v7 );
  *a3 = v10[5]; /*0x1a881f*/
  return 0; /*0x1a8826*/
}
