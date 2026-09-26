/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x185584. */
int __cdecl vol_panel_disk_label(int a1, char *__src, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v7; // ebx
  const char *v8; // ecx
  int v9; // edx
  int v10; // eax
  _UNKNOWN **v11; // edx
  char *v13; // [esp+Ch] [ebp-8h]

  v7 = 1; /*0x18558d*/
  if ( a6 ) /*0x185596*/
    v7 = 3; /*0x185598*/
  if ( !panel_req_port )
  {
    if ( a3 == 1 ) /*0x1855b0*/
    {
      v8 = aOptical; /*0x1855cc*/
      goto LABEL_14; /*0x1855d1*/
    }
    if ( a3 > 1 ) /*0x1855b2*/
    {
      if ( a3 == 2 ) /*0x1855c0*/
      {
        v8 = aScsi; /*0x1855d4*/
        goto LABEL_14; /*0x1855d9*/
      }
    }
    else if ( !a3 ) /*0x1855b8*/
    {
      v8 = aFloppy; /*0x1855c4*/
      goto LABEL_14; /*0x1855c9*/
    }
    v8 = (const char *)&unk_1E1540; /*0x1855dc*/
LABEL_14:
    switch ( v7 )
    {
      case 1:
        printf("Please Insert %s Disk '%s' in Drive %d\n", v8, __src, a4); /*0x185636*/
        break; /*0x18563b*/
      case 3:
        printf("Wrong Disk: Please Insert %s Disk '%s' in Drive %d\n", v8, __src, a4);
        break; /*0x18566b*/
    }
    return 0; /*0x1857ed*/
  }
  v13 = (char *)kalloc(0x8Cu); /*0x1856ba*/
  qmemcpy(v13, &unk_1E1480, 0x8Cu); /*0x1856cd*/
  *((_DWORD *)v13 + 3) = dword_1E13F4; /*0x1856d4*/
  *((_DWORD *)v13 + 4) = panel_req_port; /*0x1856df*/
  *((_DWORD *)v13 + 7) = v7; /*0x1856e2*/
  *((_DWORD *)v13 + 8) = 2; /*0x1856e5*/
  *((_DWORD *)v13 + 9) = dword_1E7598++; /*0x1856f1*/
  *((_DWORD *)v13 + 10) = 0; /*0x1856fa*/
  *((_DWORD *)v13 + 11) = a3; /*0x185704*/
  *((_DWORD *)v13 + 12) = a4; /*0x18570a*/
  *((_DWORD *)v13 + 13) = 0; /*0x18570d*/
  if ( strlen(__src) > 0x27 ) /*0x185730*/
    __src[39] = 0; /*0x185732*/
  if ( strlen(&byte_1E1695) > 0x27 ) /*0x18574f*/
    byte_1E16BC = 0; /*0x185751*/
  strcpy(v13 + 60, __src); /*0x185763*/
  strcpy(v13 + 100, &byte_1E1695); /*0x185774*/
  v9 = msg_send_from_kernel(v13, 1, 0); /*0x185786*/
  if ( !v9 ) /*0x18578d*/
  {
    *a7 = *((_DWORD *)v13 + 9); /*0x185798*/
    v10 = kalloc(0x14u); /*0x18579c*/
    if ( v10 ) /*0x1857a5*/
    {
      *(_DWORD *)(v10 + 8) = *((_DWORD *)v13 + 9); /*0x1857b6*/
      *(_DWORD *)(v10 + 12) = a1; /*0x1857bc*/
      *(_DWORD *)(v10 + 16) = a5; /*0x1857c2*/
      v11 = off_1E1408; /*0x1857c5*/
      if ( off_1E1408 == &off_1E1404 ) /*0x1857d1*/
        off_1E1404 = (_UNKNOWN *)v10; /*0x1857d3*/
      else
        *off_1E1408 = (_UNKNOWN *)v10; /*0x1857dc*/
      *(_DWORD *)(v10 + 4) = v11; /*0x1857de*/
      *(_DWORD *)v10 = &off_1E1404; /*0x1857e1*/
      off_1E1408 = (_UNKNOWN **)v10; /*0x1857e7*/
      return 0; /*0x1857e7*/
    }
    return 6; /*0x1857a7*/
  }
  return v9; /*0x1857f4*/
}
