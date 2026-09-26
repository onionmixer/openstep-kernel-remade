/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd300. */
Class __cdecl _class_install_relationships(int *a1, int a2)
{
  int v2; // edi
  int v3; // ebx
  Class Class; // eax
  Class result; // eax

  v2 = 0; /*0x1cd309*/
  v3 = *a1; /*0x1cd30b*/
  *(_DWORD *)(*a1 + 12) = a2; /*0x1cd310*/
  if ( a1[1] ) /*0x1cd313*/
  {
    Class = objc_getClass((const char *)a1[1]); /*0x1cd31d*/
    if ( Class ) /*0x1cd327*/
      a1[1] = (int)Class; /*0x1cd329*/
    else
      v2 = 1; /*0x1cd330*/
  }
  result = objc_getClass(*(const char **)v3); /*0x1cd338*/
  if ( result ) /*0x1cd342*/
  {
    result = result->isa; /*0x1cd344*/
    *(_DWORD *)v3 = result; /*0x1cd346*/
  }
  else
  {
    v2 = 1; /*0x1cd34c*/
  }
  if ( *(_DWORD *)(v3 + 4) ) /*0x1cd351*/
  {
    result = objc_getClass(*(const char **)(v3 + 4)); /*0x1cd35b*/
    if ( result ) /*0x1cd365*/
    {
      result = result->isa; /*0x1cd367*/
      *(_DWORD *)(v3 + 4) = result; /*0x1cd369*/
    }
    else
    {
      v2 = 1; /*0x1cd370*/
    }
  }
  else
  {
    *(_DWORD *)(v3 + 4) = a1; /*0x1cd378*/
  }
  if ( !a1[8] ) /*0x1cd37b*/
    a1[8] = (int)&emptyCache; /*0x1cd381*/
  if ( !*(_DWORD *)(v3 + 32) ) /*0x1cd388*/
    *(_DWORD *)(v3 + 32) = &emptyCache; /*0x1cd38e*/
  if ( v2 ) /*0x1cd397*/
    _objc_fatal("please link appropriate classes in your program"); /*0x1cd39e*/
  return result; /*0x1cd3a6*/
}
