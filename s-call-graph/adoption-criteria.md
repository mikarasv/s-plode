# Selection Process for the CallGraph Tool

This document outlines the methodology and criteria used to select the tool for generating call graphs within s-plode.

## 1. **Evaluation Criteria**

There are three criteria used to evaluate the tools. Each criterion is assigned a weight, and the total score determines which tool is chosen.

The following key criteria were considered during the evaluation process, along with their respective weights:

- **[Google Scorecard](https://github.com/ossf/scorecard)** (1.5): Evaluates the security aspects of the tool, including how well it manages dependencies, mitigates vulnerabilities, and ensures the integrity of its code supply chain.
- **Performance** (2): Assesses the tool's capability to handle large codebases efficiently, focusing on speed, memory usage, and scalability under heavy workloads.
- **Ease of Use** (3): Measures how intuitive and straightforward the tool is to set up and operate, considering factors such as the quality of documentation, user experience, and onboarding process.

## 2. **Tools Considered**

The tools to consider are the following:

### [networkX](https://github.com/networkx/networkx)

A Python package for the creation, manipulation, and study of the structure, dynamics, and functions of complex networks.

#### Scorecard

**Date:** 2025-01-06
**Commit:** `17e0eaea449a18305e76d7a5227b4eb49f9cb11f`
**Overall Score:** 5.5

| **Check Name**      | **Score** | **Reason**                                                 | **Details**                                                                          |
| ------------------- | --------- | ---------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| Code-Review         | 10        | All changesets reviewed                                    | -                                                                                    |
| Maintained          | 10        | 30 commits and 14 issues in the last 90 days               | -                                                                                    |
| CII-Best-Practices  | 0         | No effort to earn an OpenSSF best practices badge detected | -                                                                                    |
| Dangerous-Workflow  | 0         | Dangerous workflow patterns detected                       | Warn: script injection detected in `.github/workflows/benchmark.yml:84`              |
| Token-Permissions   | 0         | GitHub workflow tokens with excessive permissions          | Multiple warnings regarding missing top-level permissions across `.github/workflows` |
| License             | 9         | License file detected, but not FSF or OSI-compliant        | Info: License file found at `LICENSE.txt`                                            |
| Binary-Artifacts    | 10        | No binaries found in the repo                              | -                                                                                    |
| Vulnerabilities     | 10        | No existing vulnerabilities detected                       | -                                                                                    |
| Signed-Releases     | -1        | No releases found                                          | -                                                                                    |
| Pinned-Dependencies | 0         | Dependency not pinned by hash detected                     | Multiple warnings regarding GitHub Actions not pinned in `.github/workflows/*`       |

#### Performance

It took aproximately 30 seconds to build the call graph for the example.c file 10000 times.

#### Ease of use

NetworkX is designed with a user-friendly syntax, making it highly accessible. Creating, manipulating, and visualizing graphs is straightforward.
It has excellent documentation with examples for almost every feature, making it easy to learn.

### [rustworkx](https://github.com/Qiskit/rustworkx)

A high-performance, general-purpose graph library for Python, written in Rust.
**Date:** 2025-01-14
**Commit:** `752555d2b22000784464db90187c3afba60f72b1`
**Overall Score:** 6.4

| **Check Name**         | **Score** | **Reason**                                                                       | **Details**                                                                |
| ---------------------- | --------- | -------------------------------------------------------------------------------- | -------------------------------------------------------------------------- |
| Binary-Artifacts       | 10        | No binaries found in the repo.                                                   | None                                                                       |
| Branch-Protection      | -1        | Internal error: Resource not accessible by personal access token.                | None                                                                       |
| CI-Tests               | 10        | 30 out of 30 merged PRs checked by a CI test.                                    | None                                                                       |
| CII-Best-Practices     | 0         | No effort to earn an OpenSSF best practices badge detected.                      | None                                                                       |
| Code-Review            | 10        | All changesets reviewed.                                                         | None                                                                       |
| Contributors           | 10        | Project has 11 contributing companies or organizations.                          | Found contributions from: IBM, ImperialCQD, Qiskit, etc.                   |
| Dangerous-Workflow     | 10        | No dangerous workflow patterns detected.                                         | None                                                                       |
| Dependency-Update-Tool | 10        | Update tool detected.                                                            | Detected tool: Dependabot: `.github/dependabot.yml`.                       |
| Fuzzing                | 0         | Project is not fuzzed.                                                           | Warn: No fuzzer integrations found.                                        |
| License                | 10        | License file detected.                                                           | License: Apache License 2.0.                                               |
| Maintained             | 10        | Actively maintained with 30 commits and 18 issue activities in the last 90 days. | None                                                                       |
| Packaging              | 10        | Packaging workflow detected.                                                     | Found packaging via GitHub Actions.                                        |
| Pinned-Dependencies    | 0         | Dependencies not pinned by hash.                                                 | Various warnings about unpinned dependencies in workflows and scripts.     |
| SAST                   | 0         | SAST tool not run on all commits.                                                | Warn: 0 commits out of 30 checked with a SAST tool.                        |
| Security-Policy        | 10        | Security policy file detected.                                                   | Found `SECURITY.md` with linked content and disclosure information.        |
| Signed-Releases        | -1        | No releases found.                                                               | None                                                                       |
| Token-Permissions      | 0         | GitHub workflow tokens with excessive permissions detected.                      | Various warnings about insufficiently restricted permissions in workflows. |
| Vulnerabilities        | 0         | Project has known vulnerabilities.                                               |

#### Performance

It took aproximately 30 seconds to build the call graph for the example.c file 10000 times

### [pygraph](https://github.com/jciskey/pygraph)

A graph manipulation library in pure Python.
**Date:** 2025-01-06
**Commit:** `25d004d3706778fd6fbf4b687d832bcbd4281002`
**Overall Score:** 2.6
| **Check Name** | **Score** | **Reason** | **Details** |
|-------------------------|-----------|-------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Code-Review** | 1 | Found 3/27 approved changesets -- score normalized to 1 | - |
| **Maintained** | 0 | 0 commit(s) and 0 issue activity found in the last 90 days -- score normalized to 0 | - |
| **Dangerous-Workflow** | -1 | no workflows found | - |
| **Packaging** | -1 | packaging workflow not detected | Warn: no GitHub/GitLab publishing workflow detected |
| **Token-Permissions** | -1 | No tokens found | - |
| **Binary-Artifacts** | 10 | no binaries found in the repo | - |
| **Pinned-Dependencies** | -1 | no dependencies found | - |
| **CII-Best-Practices** | 0 | no effort to earn an OpenSSF best practices badge detected | - |
| **Security-Policy** | 0 | security policy file not detected | Warn: no security policy file detected |
| **Fuzzing** | 0 | project is not fuzzed | Warn: no fuzzer integrations found |
| **Vulnerabilities** | 10 | 0 existing vulnerabilities detected | - |
| **License** | 10 | license file detected | Info: project has a license file: LICENSE:0<br>Info: FSF or OSI recognized license: MIT License: LICENSE:0 |
| **Signed-Releases** | -1 | no releases found | - |
| **Branch-Protection** | 0 | branch protection not enabled on development/release branches | Warn: branch protection not enabled for branch 'master' |
| **SAST** | 0 | SAST tool is not run on all commits -- score normalized to 0 | Warn: 0 commits out of 6 are checked with a SAST tool |

### [graph-tool](https://git.skewed.de/count0/graph-tool)

An efficient Python module for manipulation and statistical analysis of graphs (a.k.a. networks).
**Date:** 2025-01-17
**Commit:** `f5a34b9a7ed578b082a774e82bea057ae6c6a43b`
**Overall Score:** 3.9
| Check Name | Score | Reason | Details |
|------------------------|-------|-----------------------------------------------|----------------------------------------------------------------------------------------------------------|
| Binary-Artifacts | 10 | no binaries found in the repo | - |
| Branch-Protection | 0 | branch protection not enabled on development/release branches | Warn: branch protection not enabled for branch 'master' |
| CI-Tests | -1 | no pull request found | - |
| CII-Best-Practices | 0 | no effort to earn an OpenSSF best practices badge detected | - |
| Code-Review | 0 | Found 0/30 approved changesets -- score normalized to 0 | - |
| Contributors | 0 | project has 0 contributing companies or organizations -- score normalized to 0 | - |
| Dangerous-Workflow | -1 | no workflows found | - |
| Dependency-Update-Tool | 0 | no update tool detected | Warn: no dependency update tool configurations found |
| Fuzzing | 0 | project is not fuzzed | Warn: no fuzzer integrations found |
| License | 10 | license file detected | Info: project has a license file: COPYING:0, Info: FSF or OSI recognized license: GNU General Public License v3.0 only: COPYING:0 |
| Maintained | 10 | 30 commit(s) and 0 issue activity found in the last 90 days -- score normalized to 10 | - |
| Packaging | 10 | packaging workflow detected | Info: Project packages its releases by way of GitHub Actions.: gitlabscorecard_flattened_ci.yaml:1819 |
| Pinned-Dependencies | 0 | dependency not pinned by hash detected -- score normalized to 0 | Warn: containerImage not pinned by hash: release/debian/Dockerfile:3, release/debian/Dockerfile:55, release/docker/Dockerfile:3, release/docker/Dockerfile:39: pin your Docker image by updating archlinux:latest to archlinux:latest@sha256:4ec00881e67eaf063c4e8d4f3a7e47eb7bc5de77edfd45477e0c6a734a60eb51, Info: 0 out of 4 containerImage dependencies pinned |
| SAST | 0 | no SAST tool detected | Warn: no pull requests merged into dev branch |
| Security-Policy | 0 | security policy file not detected | Warn: no security policy file detected, no security file to analyze (repeated warnings) |
| Signed-Releases | -1 | no releases found | - |
| Token-Permissions | -1 | No tokens found | - |
| Vulnerabilities | 10 | 0 existing vulnerabilities detected | - |

### [neo4j](https://github.com/neo4j/neo4j-python-driver)

A high performance graph store with all the features expected of a mature and robust database
**Date:** 2025-01-13
**Commit:** `e66ff235a138b844e4f80903e81107dbadeb4956`
**Overall Score:** 6.1
| **Check Name** | **Score** | **Reason** | **Details** |
|---------------------------|-----------|------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Binary-Artifacts | 10 | No binaries found in the repo | - |
| Branch-Protection | -1 | Internal error: error during branchesHandler.setup: internal error: githubv4.Query: Resource not accessible by personal access token | - |
| CI-Tests | 10 | 29 out of 29 merged PRs checked by a CI test -- score normalized to 10 | - |
| CII-Best-Practices | 0 | No effort to earn an OpenSSF best practices badge detected | - |
| Code-Review | 9 | Found 28/29 approved changesets -- score normalized to 9 | - |
| Contributors | 10 | Project has 6 contributing companies or organizations | Info: found contributions from: elastic, gnustep, neo technology, neo4j, stripe, tibber |
| Dangerous-Workflow | -1 | No workflows found | - |
| Dependency-Update-Tool | 0 | No update tool detected | Warn: no dependency update tool configurations found |
| Fuzzing | 0 | Project is not fuzzed | Warn: no fuzzer integrations found |
| License | 9 | License file detected | Warn: project license file does not contain an FSF or OSI license. Info: project has a license file: LICENSE.txt:0 |
| Maintained | 10 | 20 commit(s) and 3 issue activity found in the last 90 days -- score normalized to 10 | - |
| Packaging | -1 | Packaging workflow not detected | Warn: no GitHub/GitLab publishing workflow detected. |
| Pinned-Dependencies | 0 | Dependency not pinned by hash detected -- score normalized to 0 | Warn: containerImage not pinned by hash: benchkit/Dockerfile:1: pin your Docker image by updating python:3.12 to python:3.12@sha256:5893362478144406ee0771bd9c38081a185077fb317ba71d01b7567678a89708 |
| SAST | 0 | SAST tool is not run on all commits -- score normalized to 0 | Warn: 0 commits out of 30 are checked with a SAST tool |
| Security-Policy | 10 | Security policy file detected | Info: security policy file detected: github.com/neo4j/.github/SECURITY.md:1 |
| Signed-Releases | -1 | No releases found | - |
| Token-Permissions | -1 | No tokens found | - |
| Vulnerabilities | 10 | 0 existing vulnerabilities detected | - |

## 3. **Comparison**

The following table shows the score for each tool in every criteria:
| | Google Scorecard | Ease of use | Performance | Score |
| --------- | ---------------------------- | ----------- | ----------- | --|
| networkX | 5.5 / 10 | High | High | 0.55 \* 1.5 + 1 \* 2 + 1 \* 3 = 5.825|
| rustworkx | 6.4 / 10| Mid | High | 0.64 \* 1.5 + .66 \* 2 + 1 \* 3 = 5.28 |
| pygraph | 2.6 / 10 | Low | Low |0.26 \* 1.5 + .33 \* 2 + .33 \* 3 = 2.04 |
| graph-tool | 3.9 / 10 | Low | Low | 0.39 \* 1.5 + .33 \* 2 + .33 \* 3 = 2,235 |
| neo4j | 6.1 / 10 | Mid | High | 0.61 \* 1.5 + .66 \* 2 + 1 \* 3 = 5,235|

So the total score of the tools are:

- networkX: 5.825 / 6.5 = 0,896153846
- rustworkx: 5.28 / 6.5 = 0,812307692
- pygraph: 2.04 / 6.5 = 0,313846154
- pygraph: 2.235 / 6.5 = 0,343846154
- pygraph: 5.235 / 6.5 = 0,805384615

## 4. **Conclusion**

Given the scores the selected tool is networkX.

---
