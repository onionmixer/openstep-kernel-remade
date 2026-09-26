/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1abe3c. */
void __cdecl -[IOSCSIController releaseSCSI3Target:lun:forOwner:](
        IOSCSIController *self,
        SEL a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        id a5)
{
  $E7EB92A5B27EBB39AD62798E52927D35 *v5; // eax
  IOSCSIController *var0; // ebx
  IOSCSIController *var1; // ecx
  queue_entry *v8; // edx
  char *v9; // edx

  objc_msgSend(self->_reserveLock, sel_lock); /*0x1abe56*/
  if ( (int)a3 < -[IOSCSIController numberOfTargets](self, sel_numberOfTargets) )
  {
    v5 = -[IOSCSIController searchReserveQ:lun:](self, sel_searchReserveQ_lun_, a3, a4); /*0x1abe8e*/
    if ( v5 )
    {
      if ( v5->var2 == a5 )
      {
        var0 = (IOSCSIController *)v5->var3.var0; /*0x1abebc*/
        var1 = (IOSCSIController *)v5->var3.var1; /*0x1abebf*/
        if ( &self->_reserveQ == ($BAB6C68F9D34F0972F921D3DB17D7446 *)var0 ) /*0x1abeca*/
          v8 = v5->var3.var0; /*0x1abecc*/
        else
          v8 = (queue_entry *)&var0->super.super._deviceName[12]; /*0x1abed0*/
        *((_DWORD *)v8 + 1) = var1; /*0x1abed3*/
        if ( &self->_reserveQ == ($BAB6C68F9D34F0972F921D3DB17D7446 *)var1 ) /*0x1abede*/
          v9 = (char *)var1; /*0x1abee0*/
        else
          v9 = &var1->super.super._deviceName[12]; /*0x1abee4*/
        *(_DWORD *)v9 = var0; /*0x1abee7*/
        IOFree((int)v5, 28); /*0x1abeec*/
        --self->_reserveCount; /*0x1abef1*/
      }
      else
      {
        IOLog((int)"IOSCSIController releaseTarget: INVALID OWNER\n");
      }
    }
    else
    {
      IOLog((int)"IOSCSIController releaseTarget: NOT RESERVED\n");
    }
  }
  else
  {
    IOLog((int)"IOSCSIController releaseTarget: INVALID TARGET\n");
  }
  objc_msgSend(self->_reserveLock, sel_unlock); /*0x1abf08*/
}
