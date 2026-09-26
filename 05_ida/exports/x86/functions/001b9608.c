/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b9608. */
id __cdecl -[InputStream returnRecordedData](InputStream *self, SEL a2)
{
  $BAB6C68F9D34F0972F921D3DB17D7446 *p_regionQueue; // edx
  unsigned int v3; // eax
  int v4; // eax
  char *v5; // eax
  queue_entry *v6; // eax
  void **v8; // [esp+Ch] [ebp-18h]
  queue_entry *next; // [esp+10h] [ebp-14h]
  int v10; // [esp+14h] [ebp-10h]
  int v11; // [esp+18h] [ebp-Ch]
  size_t v12; // [esp+1Ch] [ebp-8h]
  size_t v13; // [esp+20h] [ebp-4h]

  v10 = kern_serv_kernel_task_port(); /*0x1b9620*/
  objc_msgSend(self->super.regionQueueLock, sel_lock); /*0x1b962e*/
  p_regionQueue = &self->super.regionQueue; /*0x1b9633*/
  if ( p_regionQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)p_regionQueue->next )
  {
LABEL_6:
    objc_msgSend(self->super.regionQueueLock, sel_unlock); /*0x1b9660*/
    self->wantsRecordedData = 1; /*0x1b9676*/
  }
  else
  {
    next = self->super.regionQueue.next; /*0x1b9640*/
    while ( 1 ) /*0x1b9647*/
    {
      v3 = *((_DWORD *)next + 3); /*0x1b9647*/
      if ( *(_DWORD *)next < v3 && *((_DWORD *)next + 1) > v3 ) /*0x1b9651*/
        break; /*0x1b9651*/
      next = *((queue_entry **)next + 15); /*0x1b9659*/
      if ( p_regionQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1b965e*/
        goto LABEL_6; /*0x1b965e*/
    }
    v8 = (void **)IOMalloc(0x44u); /*0x1b9687*/
    qmemcpy(v8, next, 0x44u); /*0x1b969a*/
    v4 = *((_DWORD *)next + 3); /*0x1b969c*/
    v13 = v4 - *(_DWORD *)next; /*0x1b96a6*/
    v12 = *((_DWORD *)next + 4) - v13; /*0x1b96ae*/
    v11 = *((_DWORD *)next + 2) - v4; /*0x1b96b6*/
    if ( vm_allocate_EXTERNAL(v10, v8, v13, 1) )
    {
      IOLog((int)"Audio: cannot allocate record memory\n");
      IOFree((int)v8, 68); /*0x1b96dd*/
      objc_msgSend(self->super.regionQueueLock, sel_unlock); /*0x1b96ed*/
      self->wantsRecordedData = 1; /*0x1b96f2*/
    }
    else
    {
      *((_DWORD *)next + 8) = 0; /*0x1b9713*/
      *((_DWORD *)next + 10) = 0; /*0x1b971a*/
      bcopy(*(const void **)next, *v8, v13); /*0x1b972e*/
      if ( vm_deallocate_EXTERNAL(v10, *(_DWORD *)next, *((_DWORD *)next + 4)) )
        IOLog((int)"Audio: vm_deallocate: %s\n", "MACH ERR");
      if ( vm_allocate_EXTERNAL(v10, next, v12, 1) )
      {
        IOLog((int)"Audio: cannot allocate record memory\n");
        v11 = 0; /*0x1b9786*/
        v12 = 0; /*0x1b978d*/
      }
      *((_DWORD *)next + 4) = v12; /*0x1b979d*/
      *((_DWORD *)next + 1) = *(_DWORD *)next + v12; /*0x1b97a5*/
      *((_DWORD *)next + 3) = *(_DWORD *)next; /*0x1b97ad*/
      *((_DWORD *)next + 2) = *(_DWORD *)next + v11; /*0x1b97b8*/
      v8[4] = (void *)v13; /*0x1b97c1*/
      v5 = (char *)*v8 + v13; /*0x1b97c7*/
      v8[1] = v5; /*0x1b97c9*/
      v8[2] = v5; /*0x1b97cc*/
      v8[3] = v5; /*0x1b97cf*/
      v8[12] = (void *)1; /*0x1b97d2*/
      v8[11] = (void *)1; /*0x1b97d9*/
      v6 = self->super.regionQueue.next; /*0x1b97e3*/
      if ( &self->super.regionQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)v6 ) /*0x1b97e8*/
      {
        self->super.regionQueue.next = (queue_entry *)v8; /*0x1b96ff*/
        self->super.regionQueue.prev = (queue_entry *)v8; /*0x1b9702*/
        v8[15] = v6; /*0x1b9705*/
        v8[16] = v6; /*0x1b9708*/
      }
      else
      {
        v8[16] = &self->super.regionQueue; /*0x1b97ee*/
        v8[15] = v6; /*0x1b97f1*/
        self->super.regionQueue.next = (queue_entry *)v8; /*0x1b97f4*/
        *((_DWORD *)v6 + 16) = v8; /*0x1b97f7*/
      }
      objc_msgSend(self->super.regionQueueLock, sel_unlock); /*0x1b9805*/
      self->wantsRecordedData = 0; /*0x1b980a*/
    }
  }
  return self; /*0x1b9813*/
}
