/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x184ffc. */
int __cdecl vol_panel_request(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        char *__src,
        char *a9,
        int a10,
        _DWORD *a11)
{
  const char *v11; // ecx
  int result; // eax
  int v13; // eax
  _UNKNOWN **v14; // edx
  char *v15; // [esp+Ch] [ebp-Ch]

  if ( !panel_req_port )
  {
    if ( a5 == 1 ) /*0x18501b*/
    {
      v11 = aOptical; /*0x185038*/
      goto LABEL_12; /*0x18503d*/
    }
    if ( a5 > 1 ) /*0x18501d*/
    {
      if ( a5 == 2 ) /*0x18502b*/
      {
        v11 = aScsi; /*0x185040*/
        goto LABEL_12; /*0x185045*/
      }
    }
    else if ( !a5 ) /*0x185021*/
    {
      v11 = aFloppy; /*0x185030*/
      goto LABEL_12; /*0x185035*/
    }
    v11 = (const char *)&unk_1E1540; /*0x185048*/
LABEL_12:
    switch ( a2 )
    {
      case 0:
        printf("Please Insert %s Disk %d in Drive %d\n", v11, a4, a6); /*0x18508b*/
        break; /*0x185090*/
      case 1:
        printf("Please Insert %s Disk '%s' in Drive %d\n", v11, __src, a6); /*0x1850a3*/
        break; /*0x1850a8*/
      case 2:
        printf("Wrong Disk: Please Insert %s Disk %d in Drive %d\n", v11, a4, a6);
        break; /*0x1850c0*/
      case 3:
        printf("Wrong Disk: Please Insert %s Disk '%s' in Drive %d\n", v11, __src, a6);
        break; /*0x1850d8*/
      case 4:
        printf("***Swap Device Full***\n"); /*0x1850e5*/
        break; /*0x1850ea*/
      case 5:
        printf("***File System %s Full***\n", __src); /*0x1850f9*/
        break; /*0x1850f9*/
      case 6:
        printf("Please Eject %s Disk %d\n", v11, a6); /*0x185103*/
        break; /*0x185108*/
      default:
        printf("vol_panel_request: bogus panel_type (%d)\n", a2);
        break; /*0x185119*/
    }
    return 0; /*0x185265*/
  }
  v15 = (char *)kalloc(0x8Cu); /*0x185131*/
  qmemcpy(v15, &unk_1E1480, 0x8Cu); /*0x185144*/
  *((_DWORD *)v15 + 3) = dword_1E13F4; /*0x18514c*/
  *((_DWORD *)v15 + 4) = panel_req_port; /*0x185158*/
  *((_DWORD *)v15 + 7) = a2; /*0x18515e*/
  *((_DWORD *)v15 + 8) = a3; /*0x185164*/
  *((_DWORD *)v15 + 9) = dword_1E7598++; /*0x18516d*/
  *((_DWORD *)v15 + 10) = a4; /*0x185179*/
  *((_DWORD *)v15 + 11) = a5; /*0x18517c*/
  *((_DWORD *)v15 + 12) = a6; /*0x185182*/
  *((_DWORD *)v15 + 13) = a7; /*0x185188*/
  if ( strlen(__src) > 0x27 ) /*0x1851a7*/
    __src[39] = 0; /*0x1851a9*/
  if ( strlen(a9) > 0x27 ) /*0x1851c4*/
    a9[39] = 0; /*0x1851c6*/
  strcpy(v15 + 60, __src); /*0x1851d5*/
  strcpy(v15 + 100, a9); /*0x1851e5*/
  result = msg_send_from_kernel(v15, 1, 0); /*0x1851f2*/
  if ( !result ) /*0x1851fe*/
  {
    *a11 = *((_DWORD *)v15 + 9); /*0x185209*/
    if ( a3 ) /*0x18520f*/
    {
      v13 = kalloc(0x14u); /*0x185213*/
      if ( !v13 ) /*0x18521c*/
        return 6; /*0x185223*/
      *(_DWORD *)(v13 + 8) = *((_DWORD *)v15 + 9); /*0x18522e*/
      *(_DWORD *)(v13 + 12) = a1; /*0x185234*/
      *(_DWORD *)(v13 + 16) = a10; /*0x18523a*/
      v14 = off_1E1408; /*0x18523d*/
      if ( off_1E1408 == &off_1E1404 ) /*0x185249*/
        off_1E1404 = (_UNKNOWN *)v13; /*0x18524b*/
      else
        *off_1E1408 = (_UNKNOWN *)v13; /*0x185254*/
      *(_DWORD *)(v13 + 4) = v14; /*0x185256*/
      *(_DWORD *)v13 = &off_1E1404; /*0x185259*/
      off_1E1408 = (_UNKNOWN **)v13; /*0x18525f*/
    }
    return 0; /*0x18525f*/
  }
  return result; /*0x18526a*/
}
