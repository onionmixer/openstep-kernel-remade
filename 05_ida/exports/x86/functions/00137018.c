/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137018. */
void __cdecl svcerr_noprog(SVCXPRT *a1)
{
  _BYTE v1[4]; // [esp+4h] [ebp-30h] BYREF
  int v2; // [esp+8h] [ebp-2Ch]
  int v3; // [esp+Ch] [ebp-28h]
  opaque_auth xp_verf; // [esp+10h] [ebp-24h]
  int v5; // [esp+1Ch] [ebp-18h]

  v2 = 1; /*0x137022*/
  v3 = 0; /*0x137029*/
  xp_verf = a1->xp_verf; /*0x137033*/
  v5 = 1; /*0x137042*/
  a1->xp_ops->xp_reply(a1, v1); /*0x137054*/
}
