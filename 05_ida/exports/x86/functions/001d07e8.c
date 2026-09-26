/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d07e8. */
int __cdecl task_set_special_port_EXTERNAL(int a1, int a2, int a3)
{
  int result; // eax
  mach_port_t v4; // [esp+0h] [ebp-30h]
  int v5; // [esp+8h] [ebp-28h] BYREF
  int v6; // [esp+Ch] [ebp-24h]
  int v7; // [esp+10h] [ebp-20h]
  mach_port_t reply_port; // [esp+14h] [ebp-1Ch]
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  int v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+24h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h]

  v11 = 268509186; /*0x1d0802*/
  v12 = a2; /*0x1d0805*/
  v13 = 268509190; /*0x1d080e*/
  v14 = a3; /*0x1d0811*/
  HIBYTE(v5) = 0; /*0x1d0814*/
  v6 = 40; /*0x1d0818*/
  v7 = 256; /*0x1d081f*/
  v9 = a1; /*0x1d0826*/
  reply_port = mig_get_reply_port(); /*0x1d082e*/
  v10 = 2059; /*0x1d0831*/
  result = msg_rpc(&v5, 0, 0x20u, 0, 0); /*0x1d0841*/
  if ( result ) /*0x1d084d*/
  {
    if ( result == -202 ) /*0x1d0855*/
      mig_dealloc_reply_port(v4); /*0x1d0857*/
  }
  else if ( v10 == 2159 ) /*0x1d086e*/
  {
    if ( v6 == 32 && HIBYTE(v5) == 1 && v11 == 268509186 ) /*0x1d088a*/
    {
      result = v12; /*0x1d0894*/
      if ( !v12 ) /*0x1d0899*/
        return 0; /*0x1d089b*/
    }
    else
    {
      return -300; /*0x1d088c*/
    }
  }
  else
  {
    return -301; /*0x1d0870*/
  }
  return result; /*0x1d08a0*/
}
