/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1f38. */
void __cdecl -[IODirectDevice unmapAttributeMemory](IODirectDevice *self, SEL a2)
{
  unsigned int i; // esi
  id v3; // edi
  id v4; // ebx
  id v5; // eax
  id v6; // [esp+Ch] [ebp-4h]

  if ( objc_msgSend(self->_deviceDescriptionDelegate, sel_resourcesForKey_, "PCMCIA_DEVICE_ATTR_MAPPING") ) /*0x1c1f57*/
  {
    v6 = objc_msgSend(self->_deviceDescriptionDelegate, sel_resourcesForKey_, "PCMCIA_WINDOW_LIST"); /*0x1c1f82*/
    for ( i = 0; i < (unsigned int)objc_msgSend(v6, sel_count); ++i ) /*0x1c1f85*/
    {
      v3 = objc_msgSend(v6, sel_objectAt_, i); /*0x1c1fb8*/
      v4 = objc_msgSend(v3, aObject_1); /*0x1c1fc7*/
      if ( (unsigned __int8)objc_msgSend(v4, aMemoryinterfac) && (unsigned __int8)objc_msgSend(v4, aAttributememor) ) /*0x1c1fe5*/
      {
        objc_msgSend(v4, aSetattributeme, 0); /*0x1c1ffb*/
        objc_msgSend(v4, aSetenabled, 0); /*0x1c200a*/
        v5 = objc_msgSend(v4, aSocket); /*0x1c2020*/
        objc_msgSend(v5, aSetmemoryinter); /*0x1c2029*/
        objc_msgSend(v6, sel_removeObject_, v3); /*0x1c203d*/
        objc_msgSend(v3, sel_free); /*0x1c204a*/
        break; /*0x1c2052*/
      }
    }
    objc_msgSend(self->_deviceDescriptionDelegate, sel_removeResourcesForKey_, "PCMCIA_DEVICE_ATTR_MAPPING"); /*0x1c205c*/
  }
}
