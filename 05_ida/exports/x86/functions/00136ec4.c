/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136ec4. */
int __cdecl svc_sendreply(SVCXPRT *a1, xdrproc_t a2, char *a3)
{
  _BYTE v4[4]; // [esp+4h] [ebp-30h] BYREF
  int v5; // [esp+8h] [ebp-2Ch]
  int v6; // [esp+Ch] [ebp-28h]
  opaque_auth xp_verf; // [esp+10h] [ebp-24h]
  int v8; // [esp+1Ch] [ebp-18h]
  char *v9; // [esp+20h] [ebp-14h]
  xdrproc_t v10; // [esp+24h] [ebp-10h]

  v5 = 1; /*0x136ed4*/
  v6 = 0; /*0x136edb*/
  xp_verf = a1->xp_verf; /*0x136ee5*/
  v8 = 0; /*0x136ef4*/
  v9 = a3; /*0x136efb*/
  v10 = a2; /*0x136efe*/
  return a1->xp_ops->xp_reply(a1, v4); /*0x136f0e*/
}
