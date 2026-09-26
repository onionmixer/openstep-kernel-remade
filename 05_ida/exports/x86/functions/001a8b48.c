/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8b48. */
int __cdecl -[IODirectDevice mapMemoryRange:to:findSpace:cache:](
        IODirectDevice *self,
        SEL a2,
        unsigned int a3,
        unsigned int *a4,
        char a5,
        int a6)
{
  id *v6; // esi
  id v8; // eax
  id v9; // ebx
  int v10; // eax
  id v11; // ebx
  HashTable *v12; // eax

  v6 = (id *)self->_private; /*0x1a8b5d*/
  if ( a3 >= -[IODeviceDescription numMemoryRanges](self->_deviceDescription, sel_numMemoryRanges) ) /*0x1a8b7b*/
    return -706; /*0x1a8b7d*/
  v8 = objc_msgSend(self->_deviceDescriptionDelegate, sel_resourcesForKey_, "Memory Maps"); /*0x1a8ba3*/
  v9 = objc_msgSend(v8, sel_objectAt_); /*0x1a8bb1*/
  v10 = current_task_EXTERNAL(); /*0x1a8bc0*/
  if ( a5 ) /*0x1a8bba*/
    v11 = objc_msgSend(v9, sel_mapInTarget_cache_, v10, a6); /*0x1a8bd3*/
  else
    v11 = objc_msgSend(v9, sel_mapToAddress_inTarget_cache_, *a4, v10, a6); /*0x1a8bf9*/
  if ( !v11 ) /*0x1a8c00*/
    return -701; /*0x1a8c02*/
  *a4 = (unsigned int)objc_msgSend(v11, sel_address); /*0x1a8c1c*/
  if ( !*v6 ) /*0x1a8c21*/
  {
    v12 = +[Object alloc](aHashtable, sel_alloc); /*0x1a8c40*/
    *v6 = -[HashTable initKeyDesc:](v12, sel_initKeyDesc_); /*0x1a8c4e*/
  }
  objc_msgSend(*v6, sel_insertKey_value_, *a4, v11); /*0x1a8c64*/
  return 0; /*0x1a8c6e*/
}
