/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a3d9c. */
int __cdecl sub_1A3D9C(char *__s1, _DWORD *a2, _DWORD *a3)
{
  int v3; // ebx
  const char *v4; // eax

  v3 = dword_1E866C; /*0x1a3da8*/
  if ( (int *)dword_1E866C == &dword_1E866C ) /*0x1a3db4*/
    return -704; /*0x1a3df7*/
  while ( 1 ) /*0x1a3dc4*/
  {
    v4 = (const char *)objc_msgSend(*(id *)v3, sel_name); /*0x1a3dc4*/
    if ( !strncmp(__s1, v4, 0x50u) ) /*0x1a3dce*/
      break; /*0x1a3dce*/
    v3 = *(_DWORD *)(v3 + 8); /*0x1a3dec*/
    if ( (int *)v3 == &dword_1E866C ) /*0x1a3df5*/
      return -704; /*0x1a3df5*/
  }
  *a2 = *(_DWORD *)v3; /*0x1a3ddc*/
  *a3 = *(_DWORD *)(v3 + 4); /*0x1a3de4*/
  return 0; /*0x1a3dff*/
}
