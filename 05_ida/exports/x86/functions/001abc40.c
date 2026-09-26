/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1abc40. */
id __cdecl -[IOSCSIController free](IOSCSIController *self, SEL a2)
{
  queue_entry *next; // edx
  queue_entry *p_reserveQ; // ebx
  queue_entry *v4; // esi
  int v5; // ecx
  int v6; // edx
  $BAB6C68F9D34F0972F921D3DB17D7446 *v7; // eax
  $BAB6C68F9D34F0972F921D3DB17D7446 *v8; // eax
  id v9; // edx
  objc_super v11; // [esp+Ch] [ebp-8h] BYREF

  next = self->_reserveQ.next; /*0x1abc4c*/
  if ( next && &self->_reserveQ != ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1abc5f*/
  {
    p_reserveQ = (queue_entry *)&self->_reserveQ; /*0x1abc61*/
    do /*0x1abca5*/
    {
      v4 = self->_reserveQ.next; /*0x1abc67*/
      v5 = *((_DWORD *)v4 + 5); /*0x1abc6d*/
      v6 = *((_DWORD *)v4 + 6); /*0x1abc70*/
      if ( p_reserveQ == (queue_entry *)v5 ) /*0x1abc75*/
        v7 = &self->_reserveQ; /*0x1abc77*/
      else
        v7 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v5 + 20); /*0x1abc7c*/
      v7->prev = (queue_entry *)v6; /*0x1abc7f*/
      if ( p_reserveQ == (queue_entry *)v6 ) /*0x1abc84*/
        v8 = &self->_reserveQ; /*0x1abc86*/
      else
        v8 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v6 + 20); /*0x1abc8c*/
      v8->next = (queue_entry *)v5; /*0x1abc8f*/
      IOFree((int)v4, 28); /*0x1abc94*/
    }
    while ( self->_reserveQ.next != p_reserveQ ); /*0x1abca5*/
  }
  v9 = -[IODevice unit](self, sel_unit); /*0x1abcb7*/
  if ( v9 == (id)(dword_1E516C - 1) ) /*0x1abcc4*/
    dword_1E516C = (int)v9; /*0x1abcc6*/
  v11.receiver = self; /*0x1abcd6*/
  v11.super_class = (Class)stru_1FA334.ext; /*0x1abcdf*/
  return -[IODirectDevice free](&v11, sel_free); /*0x1abcee*/
}
