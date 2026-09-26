/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1852f8. */
int __cdecl vol_panel_disk_num(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v7; // ebx
  const char *v8; // edx
  int v9; // edx
  int v10; // eax
  _UNKNOWN **v11; // edx
  char *v13; // [esp+Ch] [ebp-Ch]

  v7 = 0; /*0x185304*/
  if ( a6 ) /*0x18530a*/
    v7 = 2; /*0x18530c*/
  if ( !panel_req_port )
  {
    if ( a3 == 1 ) /*0x185323*/
    {
      v8 = aOptical; /*0x185340*/
      goto LABEL_14; /*0x185345*/
    }
    if ( a3 > 1 ) /*0x185325*/
    {
      if ( a3 == 2 ) /*0x185333*/
      {
        v8 = aScsi; /*0x185348*/
        goto LABEL_14; /*0x18534d*/
      }
    }
    else if ( !a3 ) /*0x185329*/
    {
      v8 = aFloppy; /*0x185338*/
      goto LABEL_14; /*0x18533d*/
    }
    v8 = (const char *)&unk_1E1540; /*0x185350*/
LABEL_14:
    switch ( v7 )
    {
      case 0:
        printf("Please Insert %s Disk %d in Drive %d\n", v8, a2, a4); /*0x185392*/
        break; /*0x185397*/
      case 2:
        printf("Wrong Disk: Please Insert %s Disk %d in Drive %d\n", v8, a2, a4);
        break; /*0x1853cb*/
    }
    return 0; /*0x185575*/
  }
  v13 = (char *)kalloc(0x8Cu); /*0x185439*/
  qmemcpy(v13, &unk_1E1480, 0x8Cu); /*0x18544c*/
  *((_DWORD *)v13 + 3) = dword_1E13F4; /*0x185454*/
  *((_DWORD *)v13 + 4) = panel_req_port; /*0x185460*/
  *((_DWORD *)v13 + 7) = v7; /*0x185463*/
  *((_DWORD *)v13 + 8) = 2; /*0x185466*/
  *((_DWORD *)v13 + 9) = dword_1E7598++; /*0x185473*/
  *((_DWORD *)v13 + 10) = a2; /*0x18547f*/
  *((_DWORD *)v13 + 11) = a3; /*0x185485*/
  *((_DWORD *)v13 + 12) = a4; /*0x18548b*/
  *((_DWORD *)v13 + 13) = 0; /*0x18548e*/
  if ( strlen(&_src) > 0x27 ) /*0x1854b3*/
    byte_1E16BA = 0; /*0x1854b5*/
  if ( strlen(&byte_1E1694) > 0x27 ) /*0x1854d5*/
    byte_1E16BB = 0; /*0x1854d7*/
  strcpy(v13 + 60, &_src); /*0x1854ea*/
  strcpy(v13 + 100, &byte_1E1694); /*0x1854fb*/
  v9 = msg_send_from_kernel(v13, 1, 0); /*0x18550d*/
  if ( !v9 ) /*0x185514*/
  {
    *a7 = *((_DWORD *)v13 + 9); /*0x18551f*/
    v10 = kalloc(0x14u); /*0x185523*/
    if ( v10 ) /*0x18552c*/
    {
      *(_DWORD *)(v10 + 8) = *((_DWORD *)v13 + 9); /*0x18553e*/
      *(_DWORD *)(v10 + 12) = a1; /*0x185544*/
      *(_DWORD *)(v10 + 16) = a5; /*0x18554a*/
      v11 = off_1E1408; /*0x18554d*/
      if ( off_1E1408 == &off_1E1404 ) /*0x185559*/
        off_1E1404 = (_UNKNOWN *)v10; /*0x18555b*/
      else
        *off_1E1408 = (_UNKNOWN *)v10; /*0x185564*/
      *(_DWORD *)(v10 + 4) = v11; /*0x185566*/
      *(_DWORD *)v10 = &off_1E1404; /*0x185569*/
      off_1E1408 = (_UNKNOWN **)v10; /*0x18556f*/
      return 0; /*0x18556f*/
    }
    return 6; /*0x18552e*/
  }
  return v9; /*0x18557c*/
}
