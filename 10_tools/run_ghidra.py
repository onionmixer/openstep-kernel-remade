#!/usr/bin/env python3
"""Run installed Ghidra with task-local settings; do not change HOME or installation."""
import subprocess
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
GHIDRA=Path('/home/onion/ghidra_12.1_PUBLIC')
runtime=ROOT/'04_ghidra/projects/runtime'
cmd=['java','-Xmx2G','-XX:ParallelGCThreads=2','-XX:CICompilerCount=2',
     '-Djava.awt.headless=true','-Djava.system.class.loader=ghidra.GhidraClassLoader',
     '-Dfile.encoding=UTF8','-Duser.language=en','-Duser.country=US',
     '-Dapplication.settingsdir='+str(runtime/'settings'),
     '-Dapplication.cachedir='+str(runtime/'cache'),
     '-Dapplication.tempdir='+str(runtime/'temp'),
     '-Djava.util.prefs.userRoot='+str(runtime/'prefs'),
     '-cp',str(GHIDRA/'Ghidra/Framework/Utility/lib/Utility.jar'),
     'ghidra.Ghidra','ghidra.app.util.headless.AnalyzeHeadless',
     str(ROOT/'04_ghidra/projects'),'x86-full',*sys.argv[1:]]
sys.exit(subprocess.run(cmd,cwd=ROOT).returncode)
