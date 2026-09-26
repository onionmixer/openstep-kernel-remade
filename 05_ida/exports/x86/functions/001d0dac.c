/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0dac. */
int __cdecl vm_protect_EXTERNAL(int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  mach_port_t v6; // [esp+0h] [ebp-44h]
  int v7; // [esp+Ch] [ebp-38h] BYREF
  int v8; // [esp+10h] [ebp-34h]
  int v9; // [esp+14h] [ebp-30h]
  mach_port_t reply_port; // [esp+18h] [ebp-2Ch]
  int v11; // [esp+1Ch] [ebp-28h]
  int v12; // [esp+20h] [ebp-24h]
  int v13; // [esp+24h] [ebp-20h]
  int v14; // [esp+28h] [ebp-1Ch]
  int v15; // [esp+2Ch] [ebp-18h]
  int v16; // [esp+30h] [ebp-14h]
  int v17; // [esp+34h] [ebp-10h]
  int v18; // [esp+38h] [ebp-Ch]
  int v19; // [esp+3Ch] [ebp-8h]
  int v20; // [esp+40h] [ebp-4h]

  v13 = 268509186; /*0x1d0dca*/
  v14 = a2; /*0x1d0dcd*/
  v15 = 268509186; /*0x1d0dd6*/
  v16 = a3; /*0x1d0dd9*/
  v17 = 268509184; /*0x1d0de2*/
  v18 = a4; /*0x1d0de8*/
  v19 = 268509186; /*0x1d0df1*/
  v20 = a5; /*0x1d0df4*/
  HIBYTE(v7) = 1; /*0x1d0df7*/
  v8 = 56; /*0x1d0dfb*/
  v9 = 256; /*0x1d0e02*/
  v11 = a1; /*0x1d0e09*/
  reply_port = mig_get_reply_port(); /*0x1d0e11*/
  v12 = 2024; /*0x1d0e14*/
  result = msg_rpc(&v7, 0, 0x20u, 0, 0); /*0x1d0e24*/
  if ( result ) /*0x1d0e30*/
  {
    if ( result == -202 ) /*0x1d0e38*/
      mig_dealloc_reply_port(v6); /*0x1d0e3a*/
  }
  else if ( v12 == 2124 ) /*0x1d0e52*/
  {
    if ( v8 == 32 && HIBYTE(v7) == 1 && v13 == 268509186 ) /*0x1d0e6e*/
    {
      result = v14; /*0x1d0e78*/
      if ( !v14 ) /*0x1d0e7d*/
        return 0; /*0x1d0e7f*/
    }
    else
    {
      return -300; /*0x1d0e70*/
    }
  }
  else
  {
    return -301; /*0x1d0e54*/
  }
  return result; /*0x1d0e84*/
}
