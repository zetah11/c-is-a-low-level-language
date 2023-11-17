from fuse import FUSE, Operations
from pathlib import Path
import stat

DIR = "fuse-dir"

class Fs(Operations):
    DATA = b"pointer schmointer\n"

    def read(self, path, size, offset, fh):
        print("run arbitrary python code here...")
        return Fs.DATA

    def getattr(self, path, fh = None):
        return {
            "st_mode": stat.S_IFREG | 0o777,
            "st_size": len(Fs.DATA),
        }

Path(DIR).mkdir(exist_ok = True)
FUSE(Fs(), DIR, foreground = True)

