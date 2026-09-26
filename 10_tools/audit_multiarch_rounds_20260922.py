#!/usr/bin/env python3
"""Thirty sequential, read-only static audits for OS42J m68k and SPARC evidence."""
import csv
import hashlib
import json
import re
import struct
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "09_validation/reports/multiarch-continuous-20260922"
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921"
EXPECTED = {
    "m68k": (6, "68K", "dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75"),
    "sparc": (14, "sparcb", "287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1"),
}


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def digest(data):
    return hashlib.sha256(data).hexdigest()


def count_tsv_rows(path):
    with path.open(encoding="utf-8", newline="") as handle:
        return sum(1 for _ in csv.DictReader(handle, delimiter="\t"))


def main():
    if OUT.exists():
        raise SystemExit("refusing to overwrite existing round directory")
    OUT.mkdir(parents=True)
    rounds = []

    def add(slug, details, status="pass"):
        number = len(rounds) + 1
        record = {"schema": 1, "round": number, "slug": slug, "status": status, "details": details}
        output = OUT / ("%03d-%s.json" % (number, slug))
        output.write_text(json.dumps(record, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        rounds.append(record)

    raw = {}
    inventories = {}
    for architecture, (cpu, _processor, expected_hash) in EXPECTED.items():
        raw_path = ROOT / "03_original" / architecture / "binaries/mach_kernel"
        raw[architecture] = raw_path.read_bytes()
        inventories[architecture] = read_json(ROOT / "03_original" / architecture / "inventory/macho.json")
        assert digest(raw[architecture]) == expected_hash
        assert inventories[architecture]["sha256"] == expected_hash
        assert raw[architecture][:4] == b"\xfe\xed\xfa\xce"
        assert struct.unpack_from(">i", raw[architecture], 4)[0] == cpu

    add("m68k-original-hash", {"sha256": digest(raw["m68k"]), "size": len(raw["m68k"])})
    add("sparc-original-hash", {"sha256": digest(raw["sparc"]), "size": len(raw["sparc"])})
    add("m68k-big-endian-header", {"magic": raw["m68k"][:4].hex().upper(), "cpu_type": 6})
    add("sparc-big-endian-header", {"magic": raw["sparc"][:4].hex().upper(), "cpu_type": 14})

    capability = read_json(REPORT / "ida-decompiler-capability-validation.json")
    assert capability["all_checks_passed"] is True
    for architecture, (_cpu, processor, expected_hash) in EXPECTED.items():
        target = capability["targets"][architecture]
        assert target["original_sha256_recomputed_with_python"] == expected_hash
        assert target["ida_processor"] == processor and target["ida_big_endian"] is True
        assert target["decompilation_performed"] is False
    add("m68k-canonical-ida-capability", capability["targets"]["m68k"])
    add("sparc-canonical-ida-capability", capability["targets"]["sparc"])

    text_validation = {
        architecture: read_json(REPORT / (architecture + "-ida-text-units-validation.json"))
        for architecture in EXPECTED
    }
    for architecture in EXPECTED:
        target = text_validation[architecture]
        assert target["input_sha256_match"] is True
        assert target["ida_big_endian"] is True
        assert target["continuous_address_coverage"] is True
        assert target["continuous_file_offset_coverage"] is True
        assert target["every_exported_byte_matches_original"] is True
    add("m68k-text-byte-coverage", text_validation["m68k"])
    add("sparc-text-byte-coverage", text_validation["sparc"])

    endpoint = read_json(REPORT / "xref-source-kind-audit.json")
    assert endpoint["all_checks_passed"] is True
    for architecture in EXPECTED:
        target = endpoint["targets"][architecture]
        assert target["all_xref_sources_in_original_mapped_segments"] is True
        assert sum(target["source_text_item_kind_counts"].values()) == target["xref_count"]
        assert sum(target["destination_text_item_or_mapping_counts"].values()) == target["xref_count"]
    add("m68k-xref-endpoint-partition", endpoint["targets"]["m68k"])
    add("sparc-xref-endpoint-partition", endpoint["targets"]["sparc"])

    unknown = read_json(REPORT / "m68k-unknown-text-unit-review.json")
    offset = unknown["file_offset"]
    length = unknown["length"]
    assert raw["m68k"][offset:offset + length] == bytes.fromhex(unknown["bytes"])
    assert unknown["range_end_exclusive"] == hex(int(unknown["range_start"], 16) + length)
    add("m68k-unknown-original-bytes", {"length": length, "bytes": unknown["bytes"], "file_offset": offset})
    observation = unknown["xref_destination_observation"]
    assert observation["match_count"] == 1
    assert observation["source_text_item"]["original_bytes_verified"] is True
    assert "retain IDA unknown state" in unknown["conclusion"]
    add("m68k-unknown-retention", {"observation": observation["xref_row"], "conclusion": unknown["conclusion"]}, "observed")

    objc_layout = read_json(REPORT / "objc-word-layout-audit.json")
    assert objc_layout["all_checks_passed"] is True
    assert objc_layout["targets"]["m68k"]["objc_section_count"] == 0
    add("m68k-objc-layout-absence", objc_layout["targets"]["m68k"])
    sparc_objc = objc_layout["targets"]["sparc"]
    assert sparc_objc["objc_section_count"] == 20
    assert sparc_objc["objc_sections_all_file_backed_and_4_byte_aligned"] is True
    assert sparc_objc["total_word_count"] == (
        sparc_objc["zero_word_count"] + sparc_objc["nonzero_value_in_section_count"] + sparc_objc["nonzero_value_outside_sections_count"]
    )
    add("sparc-objc-word-layout", {"section_count": sparc_objc["objc_section_count"], "word_count": sparc_objc["total_word_count"]})

    nul_export = read_json(REPORT / "objc-nul-section-export-validation.json")
    nul_tsv_validation = read_json(REPORT / "objc-nul-section-tsv-validation.json")
    assert nul_export["all_checks_passed"] is True and nul_tsv_validation["all_checks_passed"] is True
    assert nul_export["targets"]["m68k"]["selected_section_count"] == 0
    assert nul_tsv_validation["targets"]["m68k"]["tsv_record_count"] == 0
    add("m68k-objc-nul-empty", nul_tsv_validation["targets"]["m68k"])
    assert nul_export["targets"]["sparc"]["selected_section_count"] == 3
    assert nul_export["targets"]["sparc"]["record_count"] == nul_tsv_validation["targets"]["sparc"]["tsv_record_count"]
    assert nul_tsv_validation["targets"]["sparc"]["all_section_payloads_reconstructed_from_tsv"] is True
    add("sparc-objc-nul-payload-reconstruction", nul_tsv_validation["targets"]["sparc"])
    sections = nul_export["targets"]["sparc"]["sections"]
    assert all(row["trailing_nul"] and row["reconstructed_bytes_match_original"] for row in sections)
    assert sum(row["record_count"] for row in sections) == nul_export["targets"]["sparc"]["record_count"]
    add("sparc-objc-nul-section-partition", {"sections": sections})
    m68k_tsv = ROOT / nul_export["targets"]["m68k"]["tsv"]
    sparc_tsv = ROOT / nul_export["targets"]["sparc"]["tsv"]
    assert count_tsv_rows(m68k_tsv) == 0
    assert count_tsv_rows(sparc_tsv) == nul_export["targets"]["sparc"]["record_count"]
    add("objc-nul-tsv-row-counts", {"m68k": 0, "sparc": count_tsv_rows(sparc_tsv)})

    nul_xrefs = read_json(REPORT / "sparc-objc-nul-xref-endpoint-audit.json")
    assert nul_xrefs["all_checks_passed"] is True
    assert nul_xrefs["raw_cpu_type"] == 14 and nul_xrefs["nul_section_count"] == 3
    add("sparc-nul-xref-input-identity", {"sha256": nul_xrefs["original_sha256_recomputed_with_python"], "cpu": nul_xrefs["raw_cpu_type"]})
    assert sum(nul_xrefs["destination_section_counts"].values()) == nul_xrefs["xref_destination_count_in_nul_sections"]
    add("sparc-nul-xref-section-partition", nul_xrefs["destination_section_counts"])
    assert sum(nul_xrefs["destination_boundary_counts"].values()) == nul_xrefs["xref_destination_count_in_nul_sections"]
    add("sparc-nul-xref-boundary-partition", nul_xrefs["destination_boundary_counts"])
    assert nul_xrefs["destination_boundary_counts"] == {"record_start": nul_xrefs["xref_destination_count_in_nul_sections"]}
    add("sparc-nul-xref-record-start-observation", {"xref_count": nul_xrefs["xref_destination_count_in_nul_sections"]}, "observed")

    raw_xref_validation = {
        architecture: read_json(REPORT / (architecture + "-ida-xref-validation.json"))
        for architecture in EXPECTED
    }
    for architecture in EXPECTED:
        assert raw_xref_validation[architecture]["input_sha256_match"] is True
        assert raw_xref_validation[architecture]["ida_big_endian"] is True
        assert raw_xref_validation[architecture]["all_from_endpoints_mapped"] is True
    add("m68k-xref-source-mapping", raw_xref_validation["m68k"])
    add("sparc-xref-source-mapping", raw_xref_validation["sparc"])

    rejected = read_json(ROOT / "05_ida/exports/sparc/failures/ida-loader-little-endian.json")
    rejected_db = ROOT / "05_ida/databases/sparc-os42j-ida-loader-little-endian-rejected.i64"
    assert rejected_db.is_file()
    assert rejected["status"] == "rejected"
    assert rejected["input_sha256"] == EXPECTED["sparc"][2]
    assert rejected["ida_processor_from_log"] == "sparcl"
    assert "inf_is_be() returned false" in rejected["reason"]
    add("sparc-little-endian-loader-rejection-preserved", {"database": rejected_db.name, "processor": rejected["ida_processor_from_log"]})
    canonical = [ROOT / "05_ida/databases/m68k-os42j.i64", ROOT / "05_ida/databases/sparc-os42j.i64"]
    assert all(path.is_file() for path in canonical)
    assert all("rejected" not in path.name for path in canonical)
    add("canonical-database-paths", {"paths": [str(path.relative_to(ROOT)) for path in canonical]})

    paths = [ROOT / "03_original/m68k", ROOT / "03_original/sparc", ROOT / "05_ida/exports/m68k", ROOT / "05_ida/exports/sparc"]
    assert all(path.is_dir() for path in paths)
    assert all("x86" not in path.parts for path in paths)
    add("architecture-path-isolation", {"paths": [str(path.relative_to(ROOT)) for path in paths]})

    integrity = read_json(REPORT / "separation-and-integrity-validation.json")
    assert integrity["all_checks_passed"] is True
    assert integrity["m68k_unknown_destination_xref_observation"]["unknown_state_retained"] is True
    add("integrity-aggregate-state", {"all_checks_passed": integrity["all_checks_passed"], "unknown_state_retained": True})
    documents = [ROOT / "HANDOFF.md", ROOT / "02_plan/STATUS.md", REPORT / "README.md"]
    link_count = 0
    for document in documents:
        for target in re.findall(r"(?<!!)\[[^]]*\]\(([^)]+)\)", document.read_text(encoding="utf-8")):
            relative = target.split("#", 1)[0]
            if not relative or "://" in relative or relative.startswith("mailto:"):
                continue
            assert (document.parent / relative).resolve().exists()
            link_count += 1
    assert link_count <= integrity["checked_local_markdown_links"]
    add("local-markdown-links", {
        "checked_link_count": link_count,
        "integrity_recorded_link_count": integrity["checked_local_markdown_links"],
        "checked_scope_is_subset_of_integrity_scope": True,
    })

    provenance = read_json(ROOT / "03_original/installation-media/os42j/provenance.json")
    container = (ROOT / provenance["container"]["destination"]).read_bytes()
    assert digest(container) == provenance["container"]["sha256"]
    for architecture in EXPECTED:
        row = next(item for item in provenance["slices"] if item["architecture"] == architecture)
        offset, size = row["offset"], row["size"]
        assert container[offset:offset + size] == raw[architecture]
    add("fat-container-slice-reconstruction", {"container_sha256": digest(container), "architectures": list(EXPECTED)})

    assert len(rounds) == 30
    aggregate = {
        "schema": 1,
        "round_count": len(rounds),
        "pass_count": sum(row["status"] == "pass" for row in rounds),
        "observed_count": sum(row["status"] == "observed" for row in rounds),
        "rounds": rounds,
    }
    (OUT / "aggregate.json").write_text(json.dumps(aggregate, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({key: aggregate[key] for key in ("round_count", "pass_count", "observed_count")}, ensure_ascii=False))


if __name__ == "__main__":
    main()
