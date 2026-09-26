/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ddb0. */
int __cdecl kern_serv_section_by_name(int a1, char *__src, char *a3, _DWORD *a4, int *a5)
{
  int result; // eax
  mach_port_t v6; // [esp+0h] [ebp-4Ch]
  int v7; // [esp+Ch] [ebp-40h] BYREF
  int v8; // [esp+10h] [ebp-3Ch]
  int v9; // [esp+14h] [ebp-38h]
  mach_port_t reply_port; // [esp+18h] [ebp-34h]
  int v11; // [esp+1Ch] [ebp-30h]
  int v12; // [esp+20h] [ebp-2Ch]
  int v13; // [esp+24h] [ebp-28h]
  char __dst[4]; // [esp+28h] [ebp-24h] BYREF
  int v15; // [esp+2Ch] [ebp-20h]
  int v16; // [esp+30h] [ebp-1Ch]
  int v17; // [esp+34h] [ebp-18h]
  int v18; // [esp+38h] [ebp-14h]
  char v19[16]; // [esp+3Ch] [ebp-10h] BYREF

  v13 = 268533772; /*0x16ddc8*/
  strncpy(__dst, __src, 0x10u); /*0x16ddd2*/
  HIBYTE(v17) = 0; /*0x16ddd7*/
  v18 = 268533772; /*0x16dde1*/
  strncpy(v19, a3, 0x10u); /*0x16ddeb*/
  v19[15] = 0; /*0x16ddf0*/
  HIBYTE(v7) = 1; /*0x16ddf4*/
  v8 = 64; /*0x16ddf8*/
  v9 = 256; /*0x16ddff*/
  v11 = a1; /*0x16de09*/
  reply_port = mig_get_reply_port(); /*0x16de11*/
  v12 = 201; /*0x16de14*/
  result = msg_rpc(&v7, 0, 0x30u, 0, 0); /*0x16de24*/
  if ( result ) /*0x16de30*/
  {
    if ( result == -202 ) /*0x16de38*/
      mig_dealloc_reply_port(v6); /*0x16de3a*/
  }
  else
  {
    if ( v12 != 301 ) /*0x16de52*/
      return -301; /*0x16de59*/
    if ( (v8 != 48 || HIBYTE(v7) != 1) && (v8 != 32 || HIBYTE(v7) != 1 || !*(_DWORD *)__dst) || v13 != 268509186 ) /*0x16de7e*/
      return -300; /*0x16de7e*/
    result = *(_DWORD *)__dst; /*0x16de80*/
    if ( *(_DWORD *)__dst ) /*0x16de85*/
      return result; /*0x16de85*/
    if ( v15 == 268509186 && (*a4 = v16, v17 == 268509186) ) /*0x16dea1*/
    {
      *a5 = v18; /*0x16dea9*/
      return *(_DWORD *)__dst; /*0x16deab*/
    }
    else
    {
      return -300; /*0x16deb0*/
    }
  }
  return result; /*0x16deb8*/
}
