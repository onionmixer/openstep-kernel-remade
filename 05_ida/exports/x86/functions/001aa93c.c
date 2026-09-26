/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa93c. */
void __cdecl -[IOEthernet commandRequestOccurred](IOEthernet *self, SEL a2)
{
  switch ( (unsigned int)objc_msgSend(self->_driverCmd, sel_oper) ) /*0x1aa966*/
  {
    case 1u: /*0x1aa966*/
      if ( self->_isRunning || -[IOEthernet resetAndEnable:](self, sel_resetAndEnable_, 1) ) /*0x1aa9a7*/
        goto LABEL_14; /*0x1aa9b1*/
      objc_msgSend(self->_driverCmd, sel_done_, 5); /*0x1aa9bc*/
      return; /*0x1aa9bc*/
    case 2u: /*0x1aa966*/
      -[IOEthernet resetAndEnable:](self, sel_resetAndEnable_, 0); /*0x1aa9ce*/
      goto LABEL_14; /*0x1aa9d3*/
    case 4u: /*0x1aa966*/
      objc_msgSend(self->_driverCmd, sel_done_, 0); /*0x1aa9e7*/
      IOExitThread(); /*0x1aa9ec*/
      return; /*0x1aa9f1*/
    case 5u: /*0x1aa966*/
      if ( -[IOEthernet enablePromiscuousMode](self, sel_enablePromiscuousMode) ) /*0x1aaa00*/
      {
        self->_promiscEnabled = 1; /*0x1aaa0c*/
LABEL_14:
        objc_msgSend(self->_driverCmd, sel_done_, 0); /*0x1aaa99*/
      }
      else
      {
        self->_promiscEnabled = 0; /*0x1aaa18*/
        objc_msgSend(self->_driverCmd, sel_done_, 1); /*0x1aaa24*/
      }
      return;
    case 6u: /*0x1aa966*/
      -[IOEthernet disablePromiscuousMode](self, sel_disablePromiscuousMode); /*0x1aaa30*/
      self->_promiscEnabled = 0; /*0x1aaa35*/
      goto LABEL_14; /*0x1aaa3c*/
    case 7u: /*0x1aa966*/
      -[IOEthernet addMulticastAddress:](self, sel_addMulticastAddress_, &self->_multiAddr); /*0x1aaa4f*/
      -[IOEthernet enableMulticastMode](self, sel_enableMulticastMode); /*0x1aaa5c*/
      goto LABEL_14; /*0x1aaa61*/
    case 8u: /*0x1aa966*/
      -[IOEthernet removeMulticastAddress:](self, sel_removeMulticastAddress_, &self->_multiAddr); /*0x1aaa73*/
      if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->_multicastQueue.next == &self->_multicastQueue ) /*0x1aaa87*/
        -[IOEthernet disableMulticastMode](self, sel_disableMulticastMode); /*0x1aaa91*/
      goto LABEL_14; /*0x1aaa91*/
    default:
      return;
  }
}
