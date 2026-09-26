/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11f97c. */
int __cdecl sub_11F97C(int a1, int a2)
{
  _BYTE *v2; // esi
  char *v3; // edi
  int v4; // ecx
  bool v5; // zf
  int result; // eax
  int v7; // esi
  int v8; // edi
  int v9; // esi
  int v10; // eax
  const char *v11; // [esp+Ch] [ebp-4h]

  v2 = (_BYTE *)if_type(a2); /*0x11f98e*/
  v3 = a10mbEthernet_0; /*0x11f990*/
  v4 = 14; /*0x11f995*/
  result = 0; /*0x11f99b*/
  v5 = 1; /*0x11f99b*/
  do /*0x11f99d*/
  {
    if ( !v4 ) /*0x11f99d*/
      break; /*0x11f99d*/
    v5 = *v2++ == (unsigned __int8)*v3++; /*0x11f99d*/
    --v4; /*0x11f99d*/
  }
  while ( v5 ); /*0x11f99d*/
  if ( !v5 ) /*0x11f99f*/
    result = (unsigned __int8)*(v2 - 1) - (unsigned __int8)*(v3 - 1); /*0x11f9a9*/
  if ( !result ) /*0x11f9b0*/
  {
    v7 = kalloc(0x10u); /*0x11f9bd*/
    v11 = (const char *)if_name(a2); /*0x11f9c5*/
    v8 = if_unit(a2); /*0x11f9ce*/
    v9 = if_attach(0, sub_11F704, sub_11FA48, sub_11FB48, sub_11F5A8, v11, v8, "Internet Protocol", 1500, 2, 4096, v7); /*0x11fa02*/
    *(_DWORD *)(if_private(v9) + 12) = a2; /*0x11fa10*/
    v10 = if_private(v9); /*0x11fa14*/
    if_control(a2, "getaddr", v10); /*0x11fa23*/
    return printf("IP protocol enabled for interface %s%d, type \"%s\"\n", v11, v8, a10mbEthernet_1); /*0x11fa37*/
  }
  return result; /*0x11fa3f*/
}
