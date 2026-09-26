/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136fa8. */
void __cdecl svcerr_auth(SVCXPRT *a1, auth_stat a2)
{
  _BYTE v2[4]; // [esp+0h] [ebp-30h] BYREF
  int v3; // [esp+4h] [ebp-2Ch]
  int v4; // [esp+8h] [ebp-28h]
  int v5; // [esp+Ch] [ebp-24h]
  auth_stat v6; // [esp+10h] [ebp-20h]

  v3 = 1; /*0x136fb4*/
  v4 = 1; /*0x136fbb*/
  v5 = 1; /*0x136fc2*/
  v6 = a2; /*0x136fc9*/
  a1->xp_ops->xp_reply(a1, v2); /*0x136fd7*/
}
