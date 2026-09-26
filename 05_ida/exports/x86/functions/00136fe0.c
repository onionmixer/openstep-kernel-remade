/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136fe0. */
void __cdecl svcerr_weakauth(SVCXPRT *a1)
{
  _BYTE v1[4]; // [esp+0h] [ebp-30h] BYREF
  int v2; // [esp+4h] [ebp-2Ch]
  int v3; // [esp+8h] [ebp-28h]
  int v4; // [esp+Ch] [ebp-24h]
  int v5; // [esp+10h] [ebp-20h]

  v2 = 1; /*0x136fe9*/
  v3 = 1; /*0x136ff0*/
  v4 = 1; /*0x136ff7*/
  v5 = 5; /*0x136ffe*/
  a1->xp_ops->xp_reply(a1, v1); /*0x137010*/
}
