/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120968. */
int __cdecl sub_120968(int a1, int a2, int a3)
{
  int v3; // esi
  const void *v5; // eax
  __int16 v6; // bx
  __int16 v7; // ax
  void *v8; // [esp-Ch] [ebp-18h]
  size_t v9; // [esp-8h] [ebp-14h]

  v3 = if_getbuf(a1); /*0x12097a*/
  if ( v3 ) /*0x120981*/
  {
    v9 = nb_size(a2); /*0x120996*/
    v8 = (void *)nb_map(v3); /*0x1209a0*/
    v5 = (const void *)nb_map(a2); /*0x1209a2*/
    bcopy(v5, v8, v9); /*0x1209ab*/
    v6 = nb_size(v3); /*0x1209b6*/
    v7 = nb_size(a2); /*0x1209b9*/
    nb_shrink_bot(v3, v6 - v7); /*0x1209c4*/
    nb_free(a2); /*0x1209cd*/
    return if_output(a1, v3, a3); /*0x1209db*/
  }
  else
  {
    nb_free(a2); /*0x120984*/
    return 1; /*0x120989*/
  }
}
