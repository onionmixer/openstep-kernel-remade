# Page-global exact-literal operand-form audit

Report 126 counted direct absolute writes to the page-size, page-mask, and
page-shift globals. This report separately scans all 5,253 exported assembly
records for their exact address literals. Every matching record uses the
address inside an absolute memory operand; none uses it as a non-memory
literal. Therefore the export corpus contains no direct immediate-literal
construction of these exact addresses before an indirect store.

The four known direct writers were rechecked against the original kernel
bytes. This narrows one class of computed-address concern but does not exclude
addresses constructed from other values, pointer aliases, non-exported code,
or runtime stores. It does not establish runtime initialization or lifetime.

