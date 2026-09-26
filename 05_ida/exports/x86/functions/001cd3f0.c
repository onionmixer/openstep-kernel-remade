/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd3f0. */
BOOL __cdecl class_respondsToMethod(Class cls, SEL sel)
{
  Class v2; // ebx
  Method *buckets; // eax
  unsigned int i; // edx
  Method v6; // ecx
  objc_method_list **methodLists; // ecx
  SEL *v8; // edx
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  SEL *v12; // eax
  int v13; // [esp-4h] [ebp-14h]
  int v14; // [esp+0h] [ebp-10h]
  int v15; // [esp+0h] [ebp-10h]
  int v16; // [esp+0h] [ebp-10h]
  int v17; // [esp+4h] [ebp-Ch]
  int v18; // [esp+4h] [ebp-Ch]
  unsigned int mask; // [esp+Ch] [ebp-4h]

  v2 = cls; /*0x1cd3fc*/
  if ( !sel ) /*0x1cd401*/
    return 0; /*0x1cd4b1*/
  mask = cls->cache->mask; /*0x1cd421*/
  buckets = cls->cache->buckets; /*0x1cd427*/
  for ( i = (unsigned int)sel & mask; ; i = mask & (i + 1) ) /*0x1cd42d*/
  {
    if ( !buckets[i] ) /*0x1cd434*/
    {
      while ( 1 ) /*0x1cd458*/
      {
        methodLists = v2->methodLists; /*0x1cd458*/
        if ( methodLists ) /*0x1cd45d*/
          break; /*0x1cd45d*/
LABEL_15:
        v2 = v2->super_class; /*0x1cd47c*/
        if ( !v2 ) /*0x1cd481*/
        {
          v10 = NXDefaultMallocZone(v14, v17); /*0x1cd488*/
          v11 = NXDefaultMallocZone(12, v15); /*0x1cd48c*/
          v12 = (SEL *)(*(int (__stdcall **)(int, int, int, int))(v10 + 4))(v11, v13, v16, v18); /*0x1cd495*/
          *v12 = sel; /*0x1cd497*/
          v12[1] = ""; /*0x1cd499*/
          v12[2] = (SEL)_objc_msgForward; /*0x1cd4a0*/
          sub_1CD76C(cls, v12); /*0x1cd4ac*/
          return 0; /*0x1cd4ac*/
        }
      }
      while ( 1 ) /*0x1cd460*/
      {
        v8 = (SEL *)(methodLists + 2); /*0x1cd460*/
        v9 = (int)&methodLists[1][-1].method_list[0].method_imp + 3; /*0x1cd466*/
        if ( v9 >= 0 ) /*0x1cd467*/
          break; /*0x1cd467*/
LABEL_14:
        methodLists = (objc_method_list **)*methodLists; /*0x1cd476*/
        if ( !methodLists ) /*0x1cd47a*/
          goto LABEL_15; /*0x1cd47a*/
      }
      while ( *v8 != sel ) /*0x1cd46e*/
      {
        v8 += 3; /*0x1cd470*/
        if ( --v9 < 0 ) /*0x1cd474*/
          goto LABEL_14; /*0x1cd474*/
      }
      sub_1CD76C(cls, v8); /*0x1cd40d*/
      return 1; /*0x1cd417*/
    }
    v6 = buckets[i]; /*0x1cd436*/
    if ( v6->method_name == sel ) /*0x1cd43b*/
      break; /*0x1cd43b*/
  }
  return v6->method_imp != _objc_msgForward; /*0x1cd444*/
}
