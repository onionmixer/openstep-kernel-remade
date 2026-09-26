/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137060. */
void __cdecl svcerr_progvers(SVCXPRT *a1, unsigned __int32 a2, unsigned __int32 a3)
{
  _BYTE v3[4]; // [esp+4h] [ebp-30h] BYREF
  int v4; // [esp+8h] [ebp-2Ch]
  int v5; // [esp+Ch] [ebp-28h]
  opaque_auth xp_verf; // [esp+10h] [ebp-24h]
  int v7; // [esp+1Ch] [ebp-18h]
  unsigned __int32 v8; // [esp+20h] [ebp-14h]
  unsigned __int32 v9; // [esp+24h] [ebp-10h]

  v4 = 1; /*0x137070*/
  v5 = 0; /*0x137077*/
  xp_verf = a1->xp_verf; /*0x137081*/
  v7 = 2; /*0x137090*/
  v8 = a2; /*0x137097*/
  v9 = a3; /*0x13709a*/
  a1->xp_ops->xp_reply(a1, v3); /*0x1370a8*/
}
