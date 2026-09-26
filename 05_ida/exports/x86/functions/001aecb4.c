/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aecb4. */
int __cdecl -[SCSIGeneric executeRequest:buffer:client:senseBuf:](
        SCSIGeneric *self,
        int a2,
        $71639E5036F17B36840F09F8ED9B0E88 *a3,
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

  if ( (*((_BYTE *)self + 292) & 1) == 0 /*0x1aecef*/
    || LODWORD(self->_target) != *(_BYTE *)a3
    || HIDWORD(self->_target)
    || LODWORD(self->_lun) != *((unsigned __int8 *)a3 + 1)
    || HIDWORD(self->_lun) )
  {
    return 7; /*0x1aecf7*/
  }
  result = (int)objc_msgSend(self->_controller, sel_executeRequest_buffer_client_, a3, a4, a5); /*0x1aed1e*/
  if ( result == 2 )
  {
    qmemcpy(a6, (char *)a3 + 56, 0x1Au); /*0x1aed37*/
  }
  else if ( result == 3 && (*((_BYTE *)self + 284) & 1) != 0 )
  {
    v7 = -[SCSIGeneric getSense:](self, sel_getSense_, a6); /*0x1aed57*/
    if ( v7 )
    {
      v11 = IOFindNameForValue((int)v7, IOScStatusStrings); /*0x1aed77*/
      lun = self->_lun; /*0x1aed7e*/
      target = self->_target; /*0x1aed85*/
      v8 = -[IODevice name](self, sel_name); /*0x1aed8e*/
      IOLog((int)"%s: Request Sense on target %d lun %d failed (%s)\n", v8, target, lun, v11);
      return 3; /*0x1aeda1*/
    }
    else
    {
      return 2; /*0x1aed63*/
    }
  }
  return result; /*0x1aeda9*/
}
