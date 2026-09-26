/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0cb8. */
int __cdecl vm_allocate_EXTERNAL(int a1, int *a2, int a3, int a4)
{
  int result; // eax
  mach_port_t v5; // [esp+0h] [ebp-3Ch]
  int v6; // [esp+Ch] [ebp-30h] BYREF
  int v7; // [esp+10h] [ebp-2Ch]
  int v8; // [esp+14h] [ebp-28h]
  mach_port_t reply_port; // [esp+18h] [ebp-24h]
  int v10; // [esp+1Ch] [ebp-20h]
  int v11; // [esp+20h] [ebp-1Ch]
  int v12; // [esp+24h] [ebp-18h]
  int v13; // [esp+28h] [ebp-14h]
  int v14; // [esp+2Ch] [ebp-10h]
  int v15; // [esp+30h] [ebp-Ch]
  int v16; // [esp+34h] [ebp-8h]
  int v17; // [esp+38h] [ebp-4h]

  v12 = 268509186; /*0x1d0cd3*/
  v13 = *a2; /*0x1d0cd8*/
  v14 = 268509186; /*0x1d0ce1*/
  v15 = a3; /*0x1d0ce4*/
  v16 = 268509184; /*0x1d0ced*/
  v17 = a4; /*0x1d0cf3*/
  HIBYTE(v6) = 1; /*0x1d0cf6*/
  v7 = 48; /*0x1d0cfa*/
  v8 = 256; /*0x1d0d01*/
  v10 = a1; /*0x1d0d08*/
  reply_port = mig_get_reply_port(); /*0x1d0d10*/
  v11 = 2021; /*0x1d0d13*/
  result = msg_rpc(&v6, 0, 0x28u, 0, 0); /*0x1d0d23*/
  if ( result ) /*0x1d0d2f*/
  {
    if ( result == -202 ) /*0x1d0d37*/
      mig_dealloc_reply_port(v5); /*0x1d0d39*/
  }
  else
  {
    if ( v11 != 2121 ) /*0x1d0d52*/
      return -301; /*0x1d0d59*/
    if ( (v7 != 40 || HIBYTE(v6) != 1) && (v7 != 32 || HIBYTE(v6) != 1 || !v13) || v12 != 268509186 ) /*0x1d0d7e*/
      return -300; /*0x1d0d7e*/
    result = v13; /*0x1d0d80*/
    if ( v13 ) /*0x1d0d85*/
      return result; /*0x1d0d85*/
    if ( v14 == 268509186 ) /*0x1d0d8f*/
    {
      *a2 = v15; /*0x1d0d94*/
      return v13; /*0x1d0d96*/
    }
    else
    {
      return -300; /*0x1d0d9c*/
    }
  }
  return result; /*0x1d0da4*/
}
