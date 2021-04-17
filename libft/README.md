# Libft

**목차**
- [Libft](#libft)
	- [개요](#개요)
	- [함수 종류](#함수-종류)
		- [숫자 관리 함수](#숫자-관리-함수)
		- [문자 관리 함수](#문자-관리-함수)
		- [문자열 관리 함수](#문자열-관리-함수)
			- [인덱스 기반 접근](#인덱스-기반-접근)
			- [메모리 주소 기반 접근](#메모리-주소-기반-접근)
		- [메모리 관리 함수](#메모리-관리-함수)
		- [리스트 관리 함수](#리스트-관리-함수)
		- [기타](#기타)
   
## 개요
* 42 본과정 전반에 걸쳐 사용할 기본 라이브러리를 만드는 프로젝트입니다.
* 프로젝트가 제시하는 학습 목표는 lapiscine 기간 중 학습한 C언어의 개념을 제대로 이해하고 있는지 복습하는 것입니다.   
   
## 함수 종류
### 숫자 관리 함수
* [char *ft_itoa(int n)](./ft_itoa.c) : 전달받은 정수(int)를 문자열(str)로 변환하는 함수
### 문자 관리 함수
* [int	ft_isalpha(int c)](./ft_isalpha.c) : 전달받은 문자가 알파벳인지 판단하는 함수, 알파벳인 경우 1을 반환 아닌 경우 0을 반환
* [int	ft_isdigit(int c)](./ft_isdigit.c) : 전달받은 문자가 숫자인지 판단하는 함수, 숫자인 경우 1을 반환 아닌 경우 0을 반환
* [int ft_isalnum(int c)](./ft_isalnum.c) : 전달받은 문자가 숫자(0~9) 혹은 알파벳(대소문자)인지 판단하는 함수, 숫자 혹은 알파벳인 경우 1을 반환 아닌 경우 0을 반환
* [int	ft_isascii(int c)](./ft_isascii.c) : 전달받은 문자가 아스키코드(ascii)인지 판단하는 함수, 아스키코드인 경우 1을 반환 아닌 경우 0을 반환
* [int	ft_isprint(int c)](./ft_isprint.c) : 전달받은 문자가 출력가능한 아스키코드인지 판단하는 함수, 출력가능한 아스키코드인 경우 1을 반환 아닌 경우 0을 반환
* [int	ft_tolower(int c)](./ft_toupper.c) : 전달받은 문자가 알파벳 소문자인경우 대문자를 반환하는 함수
* [int	ft_tolower(int c)](./ft_tolower.c) : 전달받은 문자가 알파벳 대문자인경우 소문자를 반환하는 함수
* [void ft_putchar_fd(char c, int fd)](./ft_putchar_fd.c) : 파일디스크립터로 받은 문자를 출력하는 함수
* [void ft_putstr_fd(char *s, int fd)](./ft_putstr_fd.c) : 파일디스크립터로 받은 문자열을 출력하는 함수
* [void ft_putendl_fd(char *s, int fd)](./ft_putendl_fd.c) : 파일디스크립터로 받은 문자열과 개행을 출력하는 함수
* [void ft_putnbr_fd(int n, int fd)](./ft_putnbr_fd.c) : 파일디스크립터로 받은 숫자를 출력하는 함수
### 문자열 관리 함수
#### 인덱스 기반 접근
* [size_t	ft_strlen(const char *s)](./ft_strlen.c) : 전달받은 문자열의 길이를 반환하는 함수
* [char	*ft_strdup(const char *s1)](./ft_strdup.c) : 전달받은 문자열을 복사한 새로운 문자열을 생성하고 주소를 반환하는 함수
* [size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)](./ft_strlcpy.c) : 문자열 src에서 길이 dstsize만큼을 문자열 dst로 복사하는 함수
* [size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)](./ft_strlcat.c) : 문자열 src에서 길이 dstsize만큼을 문자열 dst뒤에 추가하는 함수
* [int	ft_strncmp(const char *s1, const char *s2, size_t n)](./ft_strncmp.c) : 문자열 s1, s2를 n만큼 비교하는 함수, 같은 경우 0을 반환 다른 경우 해당 문자의 차를 반환
* [char	*ft_strchr(const char *s, int c)](./ft_strchr.c) : 문자열 s에서 전달받은 문자 c가 있는지 찾는 함수, 있는 경우 문자열 s에서 문자의 위치를 반환 없는 경우 0을 반환
* [char	*ft_strrchr(const char *s, int c)](./ft_strrchr.c) : 문자열 s에서 전달받은 문자 c가 있는지 뒤에서부터 찾는 함수, 있는 경우 문자열 s에서 문자의 위치를 반환 없는 경우 0을 반환
* [char	*ft_strnstr(const char *haystack, const char *needle, size_t len)](./ft_strnstr.c) : 문자열 haystack에 문자열 needle이 있는지 길이 n만큼 찾는 함수, 있는 경우 needle의 첫번째 문자의 위치를 반환 없는 경우 0을 반환
* [int ft_atoi(const char *s)](./ft_atoi.c) : 전달받은 문자열을 정수(int)로 반환하는 함수
* [char *ft_substr(char const *s, unsigned int start, size_t len)](./ft_substr.c) : 전달받은 문자열을 start부터 길이(len)까지 잘라 새로운 문자열을 생성해서 그 주소를 반환하는 함수
* [char *ft_strjoin(char const *s1, char const *s2)](./ft_strjoin.c) : 전달받은 문자열 s1, s2를 합쳐 새로운 문자열을 생성해서 그 주소를 반환하는 함수
* [char *ft_strtrim(char const *s1, char const *set)](./ft_strtrim.c) : 전달받은 문자열에서 set에 해당하는 문자를 앞뒤에서 제거한 새로운 문자열을 생성해서 그 주소를 반환하는 함수
* [char **ft_split(char const *s, char c)](./ft_split.c) : 전달받은 문자열을 문자 c를 기준으로 자른 문자열 배열을 반환하는 함수
* [char *ft_strmapi(char const *s, char (*f)(unsigned int, char))](./ft_strmapi.c) : 문자열의 각 문자에 인자로 받은 함수를 적용해서 새로운 문자열을 생성하고 반환하는 함수
#### 메모리 주소 기반 접근
* [void ft_bzero(void *s, size_t n)](./ft_bzero.c) : 전달받은 문자열을 길이 n만큼 0으로 채우는 함수
* [void	*ft_memset(void *b, int c, size_t len)](./ft_memset.c) : 문자열 b에 문자 c를 길이len만큼 할당하는 함수
* [void	*ft_memchr(const void *s, int c, size_t n)](./ft_memchr.c) : 문자열 s에 문자 c를 길이 n만큼 찾는 함수, 있는 경우 문자열 s에서 문자의 위치를 반환 없는 경우 0을 반환
* [int	ft_memcmp(const void *s1, const void *s2, size_t n)](./ft_memcmp.c) : 문자열 s1과 문자열 s2이 길이n까지 같은지 확인하는 함수, 같은 경우 0을 반환 다른 경우 문자의 차를 반환
* [void	*ft_memcpy(void *dst, const void *src, size_t n)](./ft_memcpy.c) : 문자열 src을 길이 n만큼 문자열 dst에 복사하고 dst의 주소를 반환하는 함수
* [void	*ft_memccpy(void *dst, const void *src, int c, size_t n)](./ft_memccpy.c) : 문자열 src을 문자 c를 만날때 까지 dst에 복사하고 dst의 주소를 반환하는 함수, 만일 문자 c가 없다면 길이 n만큼 복사
* [void	*ft_memmove(void *dst, const void *src, size_t len)](./ft_memmove.c) : 문자열 src을 길이len만큼 문자열 dst에 복사하고 dst의 주소를 반환하는 함수, memcpy보다 안정적이다.
### 메모리 관리 함수
* [void *ft_calloc(size_t count, size_t size)](./ft_calloc.c) : 크기(size)와 길이(count)를 받아서 동적 메모리를 할당하고 값을 0으로 초기화하는 함수
### 리스트 관리 함수
* [t_list *ft_lstnew(void *content)](./ft_lstnew.c) : 새로운 리스트를 만드는 함수
* [void	ft_lstadd_front(t_list **lst, t_list *new)](./ft_lstadd_front.c) : 리스트의 앞에 새로운 리스트를 추가하는 함수
* [int ft_lstsize(t_list *lst)](./ft_lstsize.c) : 리스트의 갯수를 반환하는 함수
* [t_list	*ft_lstlast(t_list *lst)](./ft_lstlast.c) : 마지막 리스트의 주소를 반환하는 함수
* [void	ft_lstadd_back(t_list **lst, t_list *new)](./ft_lstadd_back.c) : 리스트의 끝에 새로운 리스트를 추가하는 함수
* [void	ft_lstdelone(t_list *lst, void (*del)(void *))](./ft_lstdelone.c) : 리스트의 내용을 지우고 메모리를 해제하는 함수
* [void	ft_lstclear(t_list **lst, void (*del)(void *))](./ft_lstclear.c) : 리스트에 할당된 메모리를 해제하는 함수
* [void	ft_lstiter(t_list *lst, void (*f)(void *))](./ft_lstiter.c) : 모든 리스트에 인자로 받은 함수를 적용하는 함수
* [t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))](./ft_lstmap.c) : 인자로 받은 함수를 기존 리스트에 적용해 새로운 리스트를 만들고 이를 기존 리스트에 추가하는 함수
### 기타
* [libft.h](./libft.h)
  * libft 라이브러리를 생성하기 위한 헤더파일입니다.
  * libft 라이브러리가 포함하는 함수에 대한 정보를 담고 있습니다.
* [Makefile](./Makefile)
  * libft 라이브러리를 생성할때 명령어를 자동화시켜주는 Makefile입니다.
  * `make, make all, make libft.a, make bonus`(리스트 관리 함수 포함) 명령어로 라이브러리를 생성할 수 있습니다.