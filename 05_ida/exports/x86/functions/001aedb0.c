/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aedb0. */
int __cdecl -[SCSIGeneric executeSCSI3Request:buffer:client:senseBuf:](
        SCSIGeneric *self,
        int a2,
        $1018BFDC2666C6D554C1554632BFDA34 *a3,
        int a4,
        int a5,
        char *a6)
{
  int result; // eax
  id v7; // eax
  const char *v8; // eax
  int target; // [esp-14h] [ebp-20h]
  int lun; // [esp-10h] [ebp-1Ch]
  char *v11; // [esp-Ch] [ebp-18h]

  if ( (*((_BYTE *)self + 292) & 1) == 0 /*0x1aedf1*/
    || *(_DWORD *)a3 != LODWORD(self->_target)
    || *((_DWORD *)a3 + 1) != HIDWORD(self->_target)
    || *((_DWORD *)a3 + 2) != LODWORD(self->_lun)
    || *((_DWORD *)a3 + 3) != HIDWORD(self->_lun) )
  {
    return 7; /*0x1aedf3*/
  }
  result = (int)objc_msgSend(self->_controller, sel_executeSCSI3Request_buffer_client_, a3, a4, a5); /*0x1aee17*/
  if ( result == 2 )
  {
    qmemcpy(a6, (char *)a3 + 76, 0x1Au); /*0x1aee2d*/
  }
  else if ( result == 3 && (*((_BYTE *)self + 284) & 1) != 0 )
  {
    v7 = -[SCSIGeneric getSense:](self, sel_getSense_, a6); /*0x1aee4b*/
    if ( v7 )
    {
      v11 = IOFindNameForValue((int)v7, IOScStatusStrings); /*0x1aee6b*/
      lun = self->_lun; /*0x1aee72*/
      target = self->_target; /*0x1aee79*/
      v8 = -[IODevice name](self, sel_name); /*0x1aee82*/
      IOLog((int)"%s: Request Sense on target %d lun %d failed (%s)\n", v8, target, lun, v11);
      return 3; /*0x1aee95*/
    }
    else
    {
      return 2; /*0x1aee57*/
    }
  }
  return result; /*0x1aee9d*/
}
