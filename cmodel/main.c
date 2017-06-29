#include <stdio.h>
#include <stdlib.h>


ofs myofs;
frame myframe;
task mytasks[MAX_TASKS];

void scheduler(uint32_t r2, uint32_t r3, uint32_t r4, uint32_t r5, uint32_t r6){

    uint32_t r0=0;   //main start
    uint32_t r1= myofs.sys_timer;
    r1+=1;
    myofs.sys_timer=r1;

    if(r1==0)
        //scheduler_exit;
    r8 = r2;
    r9=r3;
    r10=r4;
    r11=r5;

    r6 = myofs.current_task;
    if(r6 <0)
        continue_normal_tasks();
    myofs.stack_pos=r1;
    sleeping_tasks();
}

void continue_normal_tasks(void){

    task *ptask;
    ptask = myofs.task_array[0];

    if(ptask.entry_state == UNSCHEDULED)   //Verificar se o apontamento está correto
        sleeping_tasks();
}

void sleeping_tasks(){
    uint32_t r1 = ofs.task_array;
    r1 = r1+r0;
    int r2 = MAX_TASKS-1;
}

void process_sleeping_tasks(uint32_t r1){
    uint32_t r3 = r3+r1;
    uint32_t r4 = r3+ task.entry_state;

    if(r4 == WAIT_FOR_MUTEX)
        maybe_is_sleeping();
}

void check_to_see_if_mutex_is_free(uint32_t r3, uint32_t r0){
    uint32_t r5 = r3+task.entry_mutex;
    uint32_t r4 = r0+ofs.
}

void maybe_is_sleeping(uint32_t r4){
    if(r4 == SLEEPING)
        adjust_sleeping_value();
    if(r4!=SENT_TO_SLEEP)
        advance-counter();
}

void adjust_sleeping_value(uint32_t r3, uint32_t r4, uint32_t r5){
    r4 = r3+task.entry_target;
    r4--;
    &(r3+task.entry_target)=r4; // é igual a str r4,[r5,taskentrytarget] ?
    if(r4!=0)
        advance_counter();
    r5 = r3+mytasks[??????].entrty_target;

    if(r5==SENT_TO_SLEEP)
        do_not_advance_pc();
}

void set_state_to_running(uint32_t r5, uint32_t r3, uint32_t r4, uint32_t r5){
    r5 = r3+mytasks[??????].entry_stack;
    r4 = Frame.PC;
    r4 = r4 + 2;
    Frame.PC=r4
}

void do_not_advance_pc(uint32_t r4, uint32_t r3){
    r4 = RUNNING;
    mytasks[??????].entry_state = r4; //task.entry_state=r4;
}

void advance_counter(uint32_t r2){
    r2 = r2 - 1;
    if(r2>=0)
        process_sleeping_tasks();
}
//-----------------------------------------------------------------------------------------
//Decidir, agora, qual tarefa deve ser escalonada para o processador

void find_next_task_init(uint32_t r5, uint32_t r3){
    r5 = MAX_TASKS;
    r3=0;
    find_next_task();
}

void  find_next_task(uint32_t r6, uint32_t r2, uint32_t r0, uint32_t r1){
    r6++;
    r2 = MAX_TASKS-1;
    //ands r6,r2 pesquisar mais acerca, aparentemente representa &&, mas o código não apresenta uma condição.

    r2 = r2+r0;
    r2 = r2+myofs.task_array;   //r2 se torna o endereço da próxima tarefa

    r1 = r2 + mytasks[??????].entry_state;//task.entry_state;
    if(r1 == RUNNING)
        task_found();
    if(r1== UNSCHEDULED)
        it_is_an_unscheduled_task();

    r5--;
    if(r5!=0)
        find_next_task();
}

void schedule_idle_task(uint32_t r1, uint32_t r2, uint32_t r0){
    r1 = r0 + ofs.entry_nr_sched;
    r1++;
    ofs.entry_nr_sched=r1;

    r1 =  r0 + ofs.current_task;
    r2 = 1;
    r2 = r2*32;
    r1 = r2;     // igual a orrs r1,r2 ?
    ofs.current_task = r2;

    r0 = r0+ofs.idle_stack_pos;
    r1 = idle_task+1; //linha 224, idle_stack é um bloco, contudo não há retorno de valor da função
    Frame.PC=r1;
    restore_stack();
}

void it_is_an_unscheduled_task(uint32_t r3, uint32_t r1, uint32_t r2){
    r3 = 1;
    r1 = RUNNING;
    r1 = r2 +mytasks[??????].entry_state;//task.entry_state;
}

void task_found(uint32_t r1, uint32_t r6, uint32_t r2, uint32_t r3, uint32_t r0){
    r1 = r6;
    myofs.current_task = r1;

    r1 = r2 + mytasks[??????].entry_nr_sched;//task.entry_nr_sched;
    r1++;
    mytasks[??????].entry_nr_sched=r1;//task.entry_nr_sched = r1;

    r1 = r2 + mytasks[??????].entry_nr_sched;//task.entry_nr_sched;
    //msr PSP, r1, aparentemente não aplicável em C, uma vez q solicita o uso de um  coprocessador

    if(r3!=0)
        scheduler_exit();
}

void restore_stack(uint32_t r0, uint32_t r4, uint32_t r7, uint32_t r1, uint32_t r2, uint32_t r3, uint32_t r8,uint32_t r9,uint32_t r10, uint32_t r11){
    r1 = r0;
    r2 = r0 + 0x04;
    r3 = r0 + 0x08;
    r8 = r1;
    r9 = r2;
    r10 = r3;
    r1 = r0+0x012;
    r11 = r1;

    r0 =  r0 +0x10;
    //msr PSP,r0;
}

void scheduler_exit(){
    setbuf(stdout, 0);  // pode ser usador no lugar de isb ?
    scheduler(uint32_t r2, uint32_t r3, uint32_t r4, uint32_t r5, uint32_t r6);
}

//----------------------------------------------------------------------------------
// Para o próximo bloco, tem-se que, o  Idle task será escalonado no caso de nenhuma outra
//tarefa estar disponível para escalonamento.
// Tentará concatenar dois blocos de memória livre diferentes e então entrar em  loop.
// Também pode ser usado para colocar o sistema em repouso visando economizar energia.
//----------------------------------------------------------------------------------

void idle_task(){
    r5 =  FREE_MEMORY_START; //FREE_MEMORY_START = KERNEL_MEMORY_START + MAX_KERNEL_MEMORY +KERNEL_STACK_SIZE+IDLE_TASK_STACK_SIZE
    r4 = FREE_MEMORY_END;//FREE_MEMORY_END = KERNEL_MEMORY_START + TOTAL MEMORY-(MAX_TASKS*TASk_STACK_SIZE)
    r0 = 0;
    mutex_try_lock(); //linha 812.arm

    if(r!=0)
        enable_ints();
}

void idle_loop(uint32_t r5, uint32_t r1, uint32_t r2){
    disable_interrupts(global);
    uint32_t r1 =  r5;
    if(r1<0)
        check_next_block();
    if(r1==0)
        idle_release_locks();

    uint32_t r2 = r1+4;
    r2 = r2 + r5;
    if(r2>r4)
        idle_release_locks;

    uint32_t r3 = r2;
    if(r3<0)
        check_next_block();
    if(r3>0)
        combine_zones;

    r4 = r4 - r2; //subs r3,r4,r2 pode ser implementado
    r3 = r3- r4; // dessa forma ?

}

void combine_zones(uint32_t r1, uint32_t r3, uint32_t r5){
    r1 = r1 + r3;
    r1 = r1+4;
    r5 = r1;
}

void check_next_block(uint32_t r1, uint32_t r5, uint32_t r4){
    r1 = r1+4;
    r5 = r5+r1;

    if(r5<r4)
        idle_loop(uint32_t r5, uint32_t r1, uint32_t r2)
}

void idle_release_locks(uint32_t r0){
    r0 = 0;
    mutex_unlock();
}

void enable_ints(){
    enable_interrupts(global);
}

// Ponto de entrada principal
// Inicia memória, pilhas e o relógio do sistema e chama init()

void start(uint32_t r1, uint32_t r2){
    disable_interrupts(global);
    uint32_t r0 = KERNEL_STACK_TOP;
    // msr MSP, r0,msr, PSP, r0
    // mrs r0, CONTROL não encontrei CONTROL

    r1 = 2;
    //RESTA TERMINAR A FUNÇÃO
}
//Envia uma palavra  (1...2^32-1) para outra tarefa por meio de IPC
//r0 = id da tarefa
//r1 = a palavra a ser enviada

void start ipc_send(){
    uint32_t r2 = 0x00000800;
    uint32_t r0 = r0*2;
    r0 =  r0+ofs.task_array;
    r0= r0+r2;

    mytasks[MAX_TASKS].ipc=r1;
    return;
}

//Função para ler o valor atual de IPC
void ipc_read(){
    //PUSH LR, POSSIVELMENTE SERÁ NECESSÁRIO IMPLEMENTAR UMA PILA, ATÉ MESMO PARA
    //IMPLEMENTAR AS FUNÇÕES QUE LIDAM COM A PILHA DO SISTEMA E DO USUÁRIO
    //PUSH{Lr}
    uint32_t r1 = 0x00000800;
    r1 = get_current_task_id(); //DÚVIDA
    r0 = r0*2;
    r0 = r0+ofs.task_array;
    r0 = r0 + r1;
    mytasks[?????].ipc=r0;
    //POP {pc}
}

// ORGANIZA A PILHA PARA O PRIMEIRO ESCALONADOR DO IDLE TASK
// SIMULANDO COMO SE JA TIVESSE SIDO ESCALONADO ANTES

void init_idle_task(uint32_t r2){
    uint32_t r0 = IDLE_TASK_STACK_TOP;
    uint32_t r1 = 25; //?193?
    //rev r1,r1 transforma r1 em um registro de 4 bytes, mas o r1 já é desse tamanho
    r0 = r0 - 8;
    r0  = r0 - r1 + 4;
    r1 = idle_task+1;
    r2 = r2-4;
    r0 = r1; //stored
    r0 = ro-56;
    r1 = 0x00000800; //32bytes
    ofs.idle_stack_pos = r0;
    return ofs.idle_stack_pos;
}

//Inicializa o vetor de tarefas com os valores padrão e os ponteiros de pilha corretos
//Padrão PC é setado para init
//Nenhuma tarefa será escalonada por essa rotina

void init_task_area(){
    //push{r0-r4,lr} Usar quando implementar a lista
    uint32_t r0; //DÚVIDA, já que inicio o ro com uint32_t, ainda é necessário setar seu tamanho ?
    r0 =  r0 + ofs.task_array;
    uint32_t r1 = MAX_TASKS-1;
}

void init_loop(uint32_t r0, uint32_t r1){
    uint32_t r2 = r1*32;; //significa r2,r1, TASK_ENTRY_SHIFT_L?
    r2 = r2 + r0;

    uint32_t r3 = INACTIVE;
    mytasks[?????].entry_state = r3;
    r3 = infinite_loop()+1; //INFINITE_LOOP NÃO É UMA FUNÇÃO QUE RETORNA VALOR, COMO PODE SER ADICIONADA DE 1 ?
    mytasks[?????].pc = r3;
    uint32_t r3 = r1*32; //significa r2,r1, TASK_ENTRY_SHIFT_L?
    uint32_t r4 = 0x00001000; //16 bytes?
    r4 = r4-r3;
    r4 = r4 - 0x20; //0x100 == 4 bytes ?
    mytasks[?????].entry_state = r4;

    r1 = r1-1;
    if(r1 >= 0)
        init_loop(r0, r1);
    //pop{r0-r4,pc} usar quando implementar a pilha
}

//Cria uma tarefa
//entrada: r0 = endereço de tarefa
// retorna o id da tarefa ou -1 se der erro

void create_task(){
    //push{r4,lr}  implementar quando a pilha for criada
    disable_interrupts(global);
    uint32_t r1 = 0x00000800 //800 —> 100000  —>32 ?
    uint32_t r2 = MAX_TASKS-1;
}

void create_loop(uint32_t r0, uint32_t r2){
    //significa r2,r1, TASK_ENTRY_SHIFT_L?
    uint32_t r2 = r1*32;
    r3 = r3 + r1;
    r3 = r3 + ofs.task_array;

    uint32_t r4 = r3*32;
    if(r4 != INACTIVE)
        create_next();

    r0 = r0 + 1;
    mytasks[?????].pc = r0;
    r1 = r3 + mytasks[?????].entry_stack;
    Frame.PC = r0;

    r0 = UNSCHEDULED;
    mytasks[?????].entry_state = r0;

    r1 = 0x00000800; //32 bytes ?
    r4 = r1 + ofs.num_tasks;
    r4 = r4+1;
    ofs.num_tasks = r4;

    r0 = r2;
    create_exit();
}

void create_next(uint32_t r0, uint32_t r2){
    r2 = r2 - 1;
    if(r2 >= 0)
        create_loop(r0,r2);

    r0 = 0;
    //mvns r0,r0
}

void create_exit(){
    enable_interrupts(global);
    //pop{r4,pc}
}

//Coloca uma tarefa que vai ser identificada por seu numero
//de identificação para dormir por um numero especifico de tiques
//Se a tarefa já estiver dormindo, sobrescreve o contador
//ms com o novo valor
//Entrada: r0 = identificação da tarefa
//         r1 = quantos milisegundos para esperar

void sleep_task{
    disable_interrupts(global)

    uint32_t r2 = 0x00000800 // 32bytes
    uint32_t r0 = r0*32;
    r2 = r2 + ofs.task_array;
    r2 = r2 + r0;

    mytasks[?????].entry_target = r1;
    r1 = mytasks[?????].entry_state;
    if(r1 == SLEEPING)
        sleeping();

    r1 = SENT_TO_SLEEP;
    mytasks[?????].entry_state = r1;
}

void sleeping(){
    enable_interrupts(global);
    return;
}

//Colocar a atual tarefa para dormir por um numero específico de tiques
// entrada: r0 = esperar por quantos milisegundos

void sleep(uint32_t r1, uint32_t r0){
    uint32_t r2 = 0x00000800;// 32bytes
    r1 = r0;
    r0 = ofs.current_task;

    r0 = r0*32 //igual a lsls r0,TASK_ENTRY_SHIFT_L
    r2 = r2 + ofs.task_array;
    r2 = r2 + r0;

    mytasks[?????].entry_target = r1;
    r1 = SLEEPING;
    mytasks[?????].entry_state = r1;

    //b.

    return(r1); //  PROVISÓRIO
}

// Achar o identificador da tarefa usando o endereço de sua subrotina
// Input:  r0 = iniciar a subrotina
// Return: identificador da tarefa ou -1 caso dê errado
// AVISO; retorna o primeiro id que ele encontra que bate com o endereço
// se criar duas tarefas com o mesmo endereço, boa sorte

void get_task_id(uint32_t r0, uint32_t r1){
    r0 =  r0+ 1;
    r1 = MAX_TASKS-1;
}

void get_task_loop(){
    uint32_t r3 = 0x00000800; // 32 bytes
    r2 = r1*32; //lsls r2,r1,TASK_ENTRY_SHIFT_L;
    r2 = r2 + ofs.task_array;
    r2 = r2+ r3;

    r3 = r3 + mytasks[?????].pc;
    if(r0 == r3)
        found_it();

    r1 = r1-1;
    if(r1>=0)
        get_task_loop(uint32_t r1);
}

void found_it(uint32_t r0, uint32_t r1){
        r0 = r1;
        return r0;
}

//Retorna o numero de tarefas executando

void get_number_of_tasks(){
    uint32_t r0;
    r0 = r0 +ofs.num_tasks;
    return r0;
}

//Retorna o identificador da tarefa atual

void get_current_task_id(){
    uint32_t r0;
    r0 = r0 +  ofs.current_task;
    return r0;
}

//Retorna o timer do sistema (contador jiffie ou contador de tiques)

void get_system_timer(){
    uint32_t r0;
    r0 =  r0 + ofs.sys_timer;
    return r0;
}

//Define o valor do tempo de sistema a um valor especifico
//Input:  r0=value
//Output:  valor de tempo antigo

void set_system_timer(uint32_t r2){
    uint32_t r1;
    r2 = r2+ofs.sys_timer;
    ofs.sys_timer = r0;
    r0 = r2;
    return r0;
}

//Remove a tarefa de um vetor de escalonamento
//input: r0 =  id de thread

void kill(uint32_t r1,uint32_t r2, uint32_t r3){
    uint32_t r1;
    r2 = r0*32;
    r2 = r2 + ofs.task_array;
    r2 = r2 + r1;

    disable_interrupts(global);
    r3 = INACTIVE;
    mytasks[?????].entry_state = r3;

    r3 = r0*32;
    uint32_t = 0x00001000;

    r4 = r4 - r3;
    r4 = r4 - 0x20;
    mytasks.[?????].entry_stack = r4;

    r3 = infinite_loop()+1; //infinite não é uma função que retorna nada, como pode ser somada ?
    mytasks[?????].pc = r3;

    r3 = ofs.num_tasks;
    r3 = r3-1;
    if(r3>=0)
        keep_going();
}

void keep_going(uint32_t r3){
    ofs.num_tasks = r3;
    enable_interrupts(global);
    return
}

//Vai ser chamado por uma thread de forma a parar de executar

void exit(){
    get_current_task_id(); //call
    kill(); //call
}

//Preenche o buffer com os valores passados
//Input: r0 = endereço do buffer
//       r1 = valor a ser usado para o preenchimento
//       r2 = tamanho do buffer em tamanho word

void memset(uint32_t r2){
    //stmia r0!,{r1}
    r2 = r2 - 1;
    if(r2!=0)
        memset(r2);
    return
}

// Aloca memória
//input r0: tamanho em bytes (máximo 65532 ou FFFC)
//Retorna o endereço da memoria alocada mais recentemente ou 0 caso falhe
//
void malloc(uint32_t r4, uint32_t r5, uint32_t r0, uint32_t r1, uint32_t r3)){
    //push {r4-r5,lr} implementar quando implementar a pilha
    r4 =  r0;
    r0 = 0;
    mutex_lock();

    r0 = r4;
    r1 = 3;
    r0 = r0+3;
    //bics r0,r1;
    r1 = FREE_MEMORY_START;
    r3 = FREE_MEMORY_END;
}

void check_block(uint32_t r2, uint32_t r1){
    r2 = r2 + r1;
    if(r2<0)
        next_block();
    if(r2>0)
        found_a_block();
}

void it_was_never_allocated(uint32_t r2){
    // se for 0, nunca foi alocado, bloco deve ser: tamanho máximo - control_word
    r2 = FREE_MEMORY_END - FREE_MEMORY_START -4;
}

void found_a_block(uint32_t r0, uint32_t r2){

}

int main()
{

}
