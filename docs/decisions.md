# Decisions

## ADR-001: Versioned-era folder structure

- Status: accepted
- Context: Need to show technical progression without fake commit history.
- Decision: Represent progression with explicit `v1`, `v2`, `v3` directories and tags.
- Consequence: Hiring reviewers get a clear narrative while history remains truthful.

## ADR-002: Arena allocator as first-class primitive

- Status: accepted
- Context: Frequent small allocations create allocator noise in low-level experiments.
- Decision: Add bump-pointer arena allocator with reset semantics.
- Consequence: Allocation paths are deterministic and easy to profile.

## ADR-003: Test binaries over framework dependency

- Status: accepted
- Context: This repo should stay toolchain-light and portable.
- Decision: Use simple assertion-based test binaries compiled directly with `g++`.
- Consequence: CI remains fast and easy to debug.
