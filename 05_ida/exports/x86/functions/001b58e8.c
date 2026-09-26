/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b58e8. */
id __cdecl -[IOAudio initFromDeviceDescription:](IOAudio *self, SEL a2, id a3)
{
  id v3; // eax
  int v4; // eax
  id v6; // eax
  Class v7; // eax
  id v8; // eax
  AudioChannel *v9; // eax
  id v10; // eax
  AudioChannel *v11; // eax
  id v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  AudioCommand *v17; // eax
  int v18; // edi
  char *__src; // [esp+Ch] [ebp-114h]
  int v20; // [esp+10h] [ebp-110h] BYREF
  objc_super v21; // [esp+14h] [ebp-10Ch] BYREF
  char __dst[260]; // [esp+1Ch] [ebp-104h] BYREF

  v21.receiver = self; /*0x1b5902*/
  v21.super_class = (Class)stru_1FA474.super_class; /*0x1b590e*/
  if ( !-[IODirectDevice initFromDeviceDescription:](&v21, sel_initFromDeviceDescription_, a3) ) /*0x1b591b*/
    return nullptr; /*0x1b591b*/
  if ( -[IODirectDevice attachInterruptPort](self, sel_attachInterruptPort) ) /*0x1b592f*/
    return nullptr; /*0x1b592f*/
  v3 = -[IODirectDevice interruptPort](self, sel_interruptPort); /*0x1b5945*/
  v4 = task_self(v3); /*0x1b594e*/
  port_set_backlog_EXTERNAL(v4); /*0x1b5954*/
  if ( !-[IOAudio reset](self, sel_reset) ) /*0x1b5961*/
    return nullptr; /*0x1b596d*/
  -[IOAudio _initAudioHardwareSettings](self, sel__initAudioHardwareSettings); /*0x1b597c*/
  v6 = objc_msgSend(a3, sel_configTable); /*0x1b5989*/
  if ( v6 )
  {
    __src = (char *)objc_msgSend(v6, sel_valueForStringKey_, "Server Name"); /*0x1b59ba*/
    strncpy(__dst, __src, 257 - (strlen("KernelServerInstance") + 1)); /*0x1b59eb*/
    strcat(__dst, "KernelServerInstance"); /*0x1b59f6*/
    v7 = objc_lookUpClass(__dst); /*0x1b59ff*/
    if ( v7 )
    {
      v8 = -[objc_class kernelServerInstance](v7, aKernelserverin_0); /*0x1b5a28*/
      if ( v8 )
      {
        audioKernServInit(v8); /*0x1b5a49*/
        audio_makeIMuLawTab(); /*0x1b5a4e*/
        self->_audioPrivate = (void *)IOMalloc(28); /*0x1b5a5a*/
        if ( +[IOAudio _instance](aIoaudio, sel__instance) )
          IOLog("Audio: replacing previously registered driver\n");
        +[IOAudio _setInstance:](aIoaudio, sel__setInstance_, self); /*0x1b5a96*/
        v9 = +[Object alloc](aAudiochannel, sel_alloc); /*0x1b5ab3*/
        v10 = -[AudioChannel initOnDevice:read:](v9, sel_initOnDevice_read_); /*0x1b5abc*/
        self->_inputChannel = v10; /*0x1b5ac1*/
        +[IOAudio _addChannel:](aIoaudio, sel__addChannel_, v10); /*0x1b5ad6*/
        v11 = +[Object alloc](aAudiochannel, sel_alloc); /*0x1b5af6*/
        v12 = -[AudioChannel initOnDevice:read:](v11, sel_initOnDevice_read_); /*0x1b5aff*/
        self->_outputChannel = v12; /*0x1b5b04*/
        +[IOAudio _addChannel:](aIoaudio, sel__addChannel_, v12); /*0x1b5b19*/
        objc_msgSend(self->_inputChannel, sel_setLocalChannel_, 0); /*0x1b5b2e*/
        if ( objc_msgSend(a3, sel_numChannels) == (id)1 ) /*0x1b5b49*/
        {
          objc_msgSend(a3, sel_interrupt); /*0x1b5b53*/
          objc_msgSend(a3, sel_channel); /*0x1b5b61*/
          -[IODevice name](self, sel_name); /*0x1b5b72*/
          IOLog("%s at dma channel %d irq %d\n"); /*0x1b5b80*/
          objc_msgSend(self->_outputChannel, sel_setLocalChannel_, 0); /*0x1b5b95*/
        }
        else if ( objc_msgSend(a3, sel_numChannels) == (id)2 ) /*0x1b5bb3*/
        {
          objc_msgSend(a3, sel_channelList); /*0x1b5bbd*/
          objc_msgSend(a3, sel_interrupt); /*0x1b5bcc*/
          -[IODevice name](self, sel_name); /*0x1b5be1*/
          IOLog("%s at dma channels %d and %d irq %d\n"); /*0x1b5bef*/
          objc_msgSend(self->_outputChannel, sel_setLocalChannel_, 1); /*0x1b5c07*/
        }
        v13 = task_self(&v20); /*0x1b5c16*/
        if ( port_set_allocate_EXTERNAL(v13) )
          IOLog("Audio: port_set_allocate: %d\n");
        self->_devicePortSet = v20; /*0x1b5c3c*/
        -[IODirectDevice interruptPort](self, sel_interruptPort); /*0x1b5c4a*/
        v14 = task_self(self->_devicePortSet); /*0x1b5c5a*/
        if ( port_set_add_EXTERNAL(v14) )
          IOLog("Audio: port_set_add\n");
        v15 = task_self(&v20); /*0x1b5c7a*/
        if ( port_allocate_EXTERNAL(v15) )
          IOLog("Audio: port_allocate");
        self->_commandPort = v20; /*0x1b5c9f*/
        v16 = task_self(self->_devicePortSet); /*0x1b5cad*/
        if ( port_set_add_EXTERNAL(v16) )
          IOLog("Audio: port_set_add\n");
        self->_commandPort = IOConvertPort(self->_commandPort, 1, 0); /*0x1b5cdc*/
        v17 = +[Object alloc](aAudiocommand, sel_alloc); /*0x1b5cf8*/
        self->_audioCommand = -[AudioCommand initPort:](v17, sel_initPort_); /*0x1b5d06*/
        -[IOAudio _setTimeout:](self, sel__setTimeout_, -1); /*0x1b5d16*/
        v18 = IOForkThread(sub_1B5D68, self); /*0x1b5d29*/
        IOSetThreadPolicy(v18, 2); /*0x1b5d2e*/
        IOSetThreadPriority(v18, 30); /*0x1b5d36*/
        IOForkThread(sub_1B5EB0, self); /*0x1b5d41*/
        -[IODevice registerDevice](self, sel_registerDevice); /*0x1b5d51*/
        return self; /*0x1b5d56*/
      }
      else
      {
        IOLog("Audio: no kernel server instance\n");
        return nullptr; /*0x1b5a3e*/
      }
    }
    else
    {
      IOLog("Audio: no kernel server instance class '%s'\n");
      return nullptr; /*0x1b5a16*/
    }
  }
  else
  {
    IOLog("Audio: no configTable\n");
    return nullptr; /*0x1b599f*/
  }
}
