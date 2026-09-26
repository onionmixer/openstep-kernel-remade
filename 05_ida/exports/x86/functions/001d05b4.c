/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d05b4. */
int __cdecl port_set_add_EXTERNAL(int a1, int a2, int a3)
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

  v11 = 268509186; /*0x1d05ce*/
  v12 = a2; /*0x1d05d1*/
  v13 = 268509186; /*0x1d05da*/
  v14 = a3; /*0x1d05dd*/
  HIBYTE(v5) = 1; /*0x1d05e0*/
  v6 = 40; /*0x1d05e4*/
  v7 = 256; /*0x1d05eb*/
  v9 = a1; /*0x1d05f2*/
  reply_port = mig_get_reply_port(); /*0x1d05fa*/
  v10 = 2082; /*0x1d05fd*/
  result = msg_rpc(&v5, 0, 0x20u, 0, 0); /*0x1d060d*/
  if ( result ) /*0x1d0619*/
  {
    if ( result == -202 ) /*0x1d0621*/
      mig_dealloc_reply_port(v4); /*0x1d0623*/
  }
  else if ( v10 == 2182 ) /*0x1d063a*/
  {
    if ( v6 == 32 && HIBYTE(v5) == 1 && v11 == 268509186 ) /*0x1d0656*/
    {
      result = v12; /*0x1d0660*/
      if ( !v12 ) /*0x1d0665*/
        return 0; /*0x1d0667*/
    }
    else
    {
      return -300; /*0x1d0658*/
    }
  }
  else
  {
    return -301; /*0x1d063c*/
  }
  return result; /*0x1d066c*/
}
