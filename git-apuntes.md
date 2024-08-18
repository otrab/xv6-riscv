# Buenas Prácticas y Comandos Básicos de Git y GitHub

Este documento proporciona una guía rápida de buenas prácticas y comandos esenciales para trabajar con Git y GitHub, incluyendo cómo volver a la rama principal.

## Configuración Inicial

```bash
# Configurar nombre de usuario
git config --global user.name "Tu Nombre"

# Configurar email
git config --global user.email "tu@email.com"
```

## Autenticación con GitHub

GitHub requiere el uso de tokens de acceso personal (Personal Access Tokens) para la autenticación.

### Crear un Token de Acceso Personal

1. Ve a GitHub.com y inicia sesión.
2. Haz clic en tu foto de perfil -> "Settings" -> "Developer settings" -> "Personal access tokens" -> "Tokens (classic)".
3. Haz clic en "Generate new token", dale un nombre y selecciona los ámbitos necesarios.
4. Copia y guarda el token generado en un lugar seguro.

### Usar el Token

Usa tu nombre de usuario de GitHub y el token como contraseña cuando Git te pida autenticación.

Para almacenar las credenciales:

```bash
git config --global credential.helper store
```

## Comandos Básicos

### Iniciar un Repositorio
```bash
git init
```

### Clonar un Repositorio
```bash
git clone <url-del-repositorio>
```

### Verificar Estado
```bash
git status
```

### Añadir Cambios
```bash
git add <archivo>    # Añadir un archivo específico
git add .            # Añadir todos los archivos modificados
```

### Hacer un Commit
```bash
git commit -m "Mensaje descriptivo del commit"
```

### Subir Cambios al Repositorio Remoto
```bash
git push origin <nombre-de-la-rama>
```

### Actualizar Repositorio Local
```bash
git pull origin <nombre-de-la-rama>
```

## Trabajando con Ramas

### Crear una Nueva Rama
```bash
git branch <nombre-de-la-rama>
```

### Cambiar de Rama
```bash
git checkout <nombre-de-la-rama>
```

### Crear y Cambiar a una Nueva Rama
```bash
git checkout -b <nombre-de-la-nueva-rama>
```

### Fusionar Ramas
```bash
git merge <nombre-de-la-rama>
```

### Volver a la Rama Principal

La rama principal suele llamarse `main` o `master`. Para volver a ella:

```bash
git checkout main  # o git checkout master
```

Si necesitas actualizar la rama principal con los últimos cambios del repositorio remoto:

```bash
git checkout main  # o master
git pull origin main  # o master
```

Si tienes cambios sin commitear en tu rama actual y quieres cambiar a la principal:

1. Guarda tus cambios en un stash:
   ```bash
   git stash save "Descripción de tus cambios"
   ```

2. Cambia a la rama principal:
   ```bash
   git checkout main  # o master
   ```

3. Cuando quieras volver a tus cambios:
   ```bash
   git checkout <tu-rama-anterior>
   git stash pop
   ```

## Buenas Prácticas

1. **Commits Frecuentes**: Haz commits pequeños y frecuentes.
2. **Mensajes de Commit Descriptivos**: Usa mensajes claros y descriptivos.
3. **Usar Ramas**: Desarrolla nuevas características en ramas separadas.
4. **Pull Requests**: Usa pull requests para revisión de código.
5. **Mantén la Rama Principal Estable**: La rama principal debe contener siempre código estable.
6. **Ignorar Archivos**: Usa `.gitignore` para excluir archivos innecesarios.
7. **Revisar Cambios Antes de Commit**: Usa `git diff` para revisar tus cambios.
8. **No Reescribir el Historial Público**: Evita `git push --force` en ramas compartidas.
9. **Mantén tu Repositorio Local Actualizado**: Haz `git pull` regularmente.
10. **Usar Tags para Versiones**: Marca releases importantes con tags.

## Resolución de Problemas Comunes

### Deshacer el Último Commit (manteniendo los cambios)
```bash
git reset --soft HEAD~1
```

### Descartar Cambios Locales en un Archivo
```bash
git checkout -- <archivo>
```

### Ver el Historial de Commits
```bash
git log
```

Recuerda: La práctica hace al maestro. Cuanto más uses Git, más cómodo te sentirás con estos comandos y conceptos.