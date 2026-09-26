/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17d7e0. */
int __cdecl mach_swapon(int a1, char a2, unsigned int a3, unsigned int a4)
{
  size_t v5; // ebx
  char *v6; // edi
  int v7; // ebx
  int *v8; // eax
  unsigned int v9; // [esp+Ch] [ebp-18h]
  int *v10; // [esp+10h] [ebp-14h] BYREF
  int v11; // [esp+14h] [ebp-10h] BYREF
  int v12[2]; // [esp+18h] [ebp-Ch] BYREF
  size_t __n; // [esp+20h] [ebp-4h]

  if ( !suser() ) /*0x17d7e9*/
    return 13; /*0x17d7f2*/
  *(_BYTE *)(dword_1E875C + 104) = 0; /*0x17d801*/
  v11 = 0; /*0x17d805*/
  if ( pn_get(a1, 0, v12) ) /*0x17d816*/
    return 22; /*0x17d824*/
  v5 = __n; /*0x17d830*/
  v9 = __n + 1; /*0x17d836*/
  v6 = (char *)kalloc(__n + 1); /*0x17d83f*/
  strncpy(v6, (const char *)v12[1], v5); /*0x17d847*/
  v6[v9 - 1] = 0; /*0x17d84f*/
  v7 = lookuppn((int)v12, 1, nullptr, &v11); /*0x17d862*/
  pn_free(v12); /*0x17d868*/
  if ( !v7 ) /*0x17d872*/
  {
    if ( *(_DWORD *)(v11 + 40) == 1 ) /*0x17d87b*/
    {
      v10 = (int *)dword_1E7288; /*0x17d889*/
      if ( (int *)dword_1E7288 == &dword_1E7288 ) /*0x17d891*/
        goto LABEL_13; /*0x17d891*/
      do /*0x17d8a6*/
      {
        if ( v10[2] == v11 ) /*0x17d89a*/
          break; /*0x17d89a*/
        v10 = (int *)*v10; /*0x17d89e*/
      }
      while ( v10 != &dword_1E7288 ); /*0x17d8a6*/
      if ( v10 == &dword_1E7288 ) /*0x17d8af*/
      {
LABEL_13:
        v7 = vnode_pager_file_init(&v10, v11, a3, a4); /*0x17d8cd*/
        if ( !v7 ) /*0x17d8d4*/
        {
          v8 = v10; /*0x17d8d6*/
          v10[11] = a2 & 1; /*0x17d8df*/
          v8[10] = (int)v6; /*0x17d8e2*/
          v6 = nullptr; /*0x17d8e5*/
        }
      }
      else
      {
        v7 = 16; /*0x17d8b1*/
      }
    }
    else
    {
      v7 = 22; /*0x17d87d*/
    }
  }
  if ( v11 ) /*0x17d8ec*/
    vn_rele(v11); /*0x17d8ef*/
  if ( v6 ) /*0x17d8f9*/
    kfree((int)v6, v9); /*0x17d900*/
  return v7; /*0x17d90a*/
}
