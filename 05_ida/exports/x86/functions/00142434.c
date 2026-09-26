/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142434. */
int __cdecl sub_142434(_DWORD *a1)
{
  int v1; // eax
  int v2; // ebx
  int v3; // ebx
  _DWORD *v4; // eax
  void *v6; // [esp+8h] [ebp-8h] BYREF
  _DWORD *v7; // [esp+Ch] [ebp-4h] BYREF

  v1 = a1[4]; /*0x14243f*/
  v2 = *(_DWORD *)(v1 + 4); /*0x142442*/
  if ( v2 ) /*0x142447*/
  {
    v7 = (_DWORD *)(v1 + 4); /*0x14245f*/
    while ( 2 ) /*0x142475*/
    {
      v3 = sub_142600(v2, a1, 1, &v7, &v6); /*0x142475*/
      if ( v3 ) /*0x14247c*/
      {
        sub_14282C(v6); /*0x142486*/
        switch ( v3 ) /*0x14249a*/
        {
          case 1: /*0x14249a*/
            *v7 = *((_DWORD *)v6 + 5); /*0x1424c1*/
            sub_14286C(v6); /*0x1424c7*/
            break; /*0x1424cc*/
          case 2: /*0x14249a*/
            if ( *((_DWORD *)v6 + 1) == a1[1] ) /*0x1424d9*/
            {
              *((_DWORD *)v6 + 1) = a1[2] + 1; /*0x142454*/
            }
            else
            {
              sub_1427B4(v6, (int)a1); /*0x1424e1*/
              *((_DWORD *)v6 + 5) = a1[5]; /*0x1424ec*/
            }
            break; /*0x1424ef*/
          case 3: /*0x14249a*/
            *v7 = *((_DWORD *)v6 + 5); /*0x1424fd*/
            v2 = *((_DWORD *)v6 + 5); /*0x142502*/
            sub_14286C(v6); /*0x142506*/
            continue; /*0x14250e*/
          case 4: /*0x14249a*/
            v4 = v6; /*0x142514*/
            *((_DWORD *)v6 + 2) = a1[1] - 1; /*0x14251b*/
            v7 = v4 + 5; /*0x142521*/
            v2 = v4[5]; /*0x142524*/
            continue; /*0x142527*/
          case 5: /*0x14249a*/
            *((_DWORD *)v6 + 1) = a1[2] + 1; /*0x142533*/
            break; /*0x142533*/
          default:
            return 0;
        }
      }
      break;
    }
  }
  return 0; /*0x14253b*/
}
