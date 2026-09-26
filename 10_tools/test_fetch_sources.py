"""Offline regression checks for historical archives with misleading extensions."""
import io
import tarfile
import tempfile
import unittest
from pathlib import Path

from fetch_sources import validate_file


class ArchiveValidationTests(unittest.TestCase):
    def test_plain_tar_with_gzip_extension(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "kernel-1.tar.gz.part"
            with tarfile.open(path, "w") as archive:
                member = tarfile.TarInfo("kernel/test.c")
                payload = b"int test;\n"
                member.size = len(payload)
                archive.addfile(member, io.BytesIO(payload))
            self.assertEqual(validate_file(path, "archive"),
                             {"archive_format": "tar", "archive_member_count": 1})

    def test_gzip_archive(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "architecture.tar.gz"
            with tarfile.open(path, "w:gz") as archive:
                archive.addfile(tarfile.TarInfo("test.h"), io.BytesIO())
            self.assertEqual(validate_file(path, "archive")["archive_format"], "tar+gzip")

    def test_truncated_payload_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "truncated.tar.gz.part"
            member = tarfile.TarInfo("kernel/test.c")
            member.size = 4096
            path.write_bytes(member.tobuf() + b"short")
            with self.assertRaises(tarfile.ReadError):
                validate_file(path, "archive")

    def test_html_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "error.tar.gz.part"
            path.write_text("<html>download unavailable</html>")
            with self.assertRaises(tarfile.ReadError):
                validate_file(path, "archive")


if __name__ == "__main__":
    unittest.main()
