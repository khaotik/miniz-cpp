  .data
  .global _test_xlsx_start
_test_xlsx_start:
  .incbin __raw_file_path__

  .global _test_xlsx_end
_test_xlsx_end:    
  .byte 0

  .global _test_xlsx_size
_test_xlsx_size:
  .quad _test_xlsx_end - _test_xlsx_start
