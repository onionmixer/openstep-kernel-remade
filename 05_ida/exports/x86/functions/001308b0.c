/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1308b0. */
int __cdecl sub_1308B0(int a1, const char *a2, const char *a3, void *a4)
{
  int v4; // eax
  _DWORD *v5; // ebx
  int v7; // [esp+10h] [ebp-30h]
  int v8; // [esp+1Ch] [ebp-24h] BYREF
  _BYTE v9[32]; // [esp+20h] [ebp-20h] BYREF

  while ( 1 )
  {
    v4 = pmap_kgetport(a1, 100005, 1, 17); /*0x1308c9*/
    if ( v4 == -1 ) /*0x1308d4*/
      return 15; /*0x1309b1*/
    if ( v4 != 1 ) /*0x1308dd*/
      break; /*0x1308dd*/
    printf("mountnfs: %s:%s portmap not responding\n", a2, a3);
  }
  while ( 1 )
  {
    v5 = (_DWORD *)clntkudp_create(a1, 100005, 1, 5, *(_DWORD *)(active_u + 28)); /*0x130920*/
    v7 = (*(int (__cdecl **)(_DWORD *, int, int (__cdecl *)(XDR *, bp_path_t *), const char **, int (__cdecl *)(XDR *, fhstatus *), int *, int, _DWORD))v5[1])( /*0x130947*/
           v5,
           1,
           xdr_bp_path_t,
           &a3,
           xdr_fhstatus,
           &v8,
           3,
           0);
    (*(void (__cdecl **)(_DWORD))(*(_DWORD *)(*v5 + 32) + 16))(*v5); /*0x130956*/
    (*(void (__cdecl **)(_DWORD *))(v5[1] + 16))(v5); /*0x13095f*/
    if ( v7 != 5 ) /*0x13096a*/
      break; /*0x13096a*/
    printf("mountnfs: %s:%s mount server not responding\n", a2, a3);
  }
  if ( v7 ) /*0x130986*/
    return v7; /*0x1309b4*/
  *(_WORD *)(a1 + 2) = __ROR2__(2049, 8); /*0x130994*/
  qmemcpy(a4, v9, 0x20u); /*0x1309a4*/
  return v8; /*0x1309ba*/
}
